import csv
import json

def read_csv(file_path):
    with open(file_path, encoding='utf-8') as file:
        csv_reader = csv.DictReader(file)
        #첫 행을 header로 건너뜀
        header = csv_reader.fieldnames
        valid_rows = []
        scores = []

        for row in csv_reader:
            name = row['name']  
            #score를 int로 변환하고 범위를 검사
            try:
                score = int(row['score'])
                #0~100 범위 검사
                if score < 0 or score > 100:
                    #오류행은 이유를 출려 후 검사
                    print('허용 범위 초과')
                    continue

                valid_rows.append({'name': name, 'score': score})
                scores.append(score)
                print(f'{name} {score}')    

            #오류행은 이유를 출력 후 검사
            except ValueError:
                print('숫자 변환 실패')
                
    #유효행은 clean_students.csv로 저장
    with open('clean_students.csv', 'w', newline='', encoding='utf-8') as file:
        csv_writer = csv.DictWriter(file, fieldnames=header)
        csv_writer.writeheader()
        csv_writer.writerows(valid_rows)

    total_students = len(valid_rows)
    average_score = sum(scores) / total_students if total_students > 0 else 0
    max_score = max(scores) if scores else 0

    #인원수·평균·최고점을 summary.json으로 저장
    with open('summary.json', 'w', encoding='utf-8') as file:
        summary = {
            'total_students': total_students,
            'average_score': average_score,
            'max_score': max_score
        }
        json.dump(summary, file, ensure_ascii=False, indent=4)

read_csv('students.csv')