# 행동 데이터 기반 성격 유형 예측 및 통계 분석 프로젝트
> **SNS 활동 지표와 성격 유형 간 상관 관계 분석**

## 프로젝트 개요
현대 사회의 필수 소통 수단인 SNS의 활동 데이터와 개인의 성격 유형(외향성/내향성) 간의 상관관계를 객관적인 데이터로 검증하였습니다.   
'외향적인 사람이 온라인에서도 더 활발할 것인가?'라는 가설을 통계적으로 분석하였습니다.

## Language & Libraries
* **Language** : Python
* **Libraries**
    - Data Analysis : Pandas, NumPy
    - Visualization : Matplotlib, Seaborn
    - Machine Learning : Scikit-learn (Linear Regression)

## Dataset
Dataset 출처 : https://www.kaggle.com/datasets/timothyadeyemi/personality-dataset
| 변수명 | 설명 | 범위 |
| ----- | ---- | --- |
| `Time_spent_Alone` | 하루 중 혼자 보내는 시간 | 0~11시간 |
| `Social_event_attendance` | 사회 모임 참여 횟수 | 0~10회 |
| `Going_outside` | 외출_빈도 | 0~7일 |
| `Post_frequency` | SNS 게시물 업로드 빈도 | 0~10회 |
| `Friends_circle_size` | 친한 친구 수 | 0~15명 |
| `Personality` | 성격 유형 | Extrovert / Introvert |

## 분석 프로세스
### 1. 데이터 전처리
* **중앙값 대체** : Time_spent_Alone, Social_event_attendance, Going_outside, Post_frequency
* **평균값 대체** : Firends_circle_size
* **최빈값 대체** : Drained_after_socializing
* **삭제** : Stage_fear
* Target변수로 사용할 Personality를 수치형으로 변경 (0 Introvert, 1 Extrovert)

### 2. 데이터 분석 및 시각화
* **SNS 게시물 업로드 분포** : 전체 사용자의 약 70% 이상이 게시 빈도 4 이하의 구간에 집중되어 있음을 확인하였습니다.
* **성격 유형별 평균 비교** : 외향형(5.58회)이 내향형(1.41)회보다 평균적으로 약 4배 높은 SNS 게시물 업로드 빈도를 보였습니다.
* **행동 패턴 분석** : 내향형은 SNS 게시 빈도가 0~2회 구간에 밀집되어있으며, 외향형은 3회 이상의 구간에서 고르게 분포하는 특징을 보였습니다.

### 3. 회귀 분석을 통한 예측
Scikit-learn의 LinearRegression을 사용하여 SNS 게시 빈도에 따른 외향형 확률을 계산하였습니다.
* **독립 변수 (X)** : Post_frequency (SNS_게시빈도)
* **종속 변수 (Y)** : Personality (성격유형_int - 수치형으로 변경된 데이터)
* **결과** : SNS 활동 빈도가 증가할수록 해당 사용자가 외향형일 확률이 증가함을 확인하였습니다.

## Project Structure 
```
Data-Mining/
├── personality_dataset.csv
├── sns_personality_analysis.ipynb
└── README.md      
```
