# Bike Renting System
## user
- 租車使用者
    - 會員註冊/登入
        - 可設定帳密、手機號碼、信用卡資訊
        - 查看租換車歷史紀錄
        - 查看優惠券
    - 隨時隨地租車還車
        - 還的點若太遠，電量不足就無法還車
        - 還車付款時可選擇優惠券
        - 金額用距離來算
    - 查詢附近哪裡有車
        - 可設定附近幾公里範圍內
        - 壞掉的車不能查詢
        - 資訊包含：車牌號碼、車位置、電量
    - 幫車充電
        - 充電可回饋優惠券（不能當次使用）
        - 充電的點若太遠，電量不足就無法充電
- 維修人員
    - 故障車資訊包含：車牌號碼、車位置（經緯度）、電量、狀態（故障/維修中/正常）
    - 將故障車狀態調整為維修中/正常
    - 幫車充電
        - 幫低於20%的車充滿電
        - 車充完電會被放在隨機位置
            - 範圍：
                >經度：121.511162 - 121.567045
                >緯度：25.026708 - 25.068277

## 規格定義
- 故障車資訊
    - 車牌
    - 所在位置（經緯度）
    - 狀態（故障/維修中/正常）
    - 電量
- 可租借車資訊
    - 車牌
    - 所在位置（經緯度）
    - 電量
- 充電站資訊
    - 所在位置（經緯度）
- 會員資訊
    - 帳號
    - 密碼
    - 電話
    - email
    - 姓名
    - 信用卡資訊
- 租借車歷史紀錄
    - 日期
    - 總金額
    - 起始＆終點位置（經緯度）
    - 距離
    - 借＆還時間、總時間
    - 充電次數
    - 有無使用優惠券
## 評分
### 基本系統功能 (60%)
- 租車使用者 (40%)
- 維修人員 (20%)
### 基本技術 (10%)
- JDBC (10%) 
### 其他評分依據(60%) 
- 使用地圖API (e.g. Google API, JOSM API…) 做距離計算 (5%) 
- 呈現地圖畫面 (15%)
- 有寫完整註解 (6%)
- Android APP / GUI (4%)
- JavaFX (8%)
- Design pattern (4%)
- Package規劃 (4%)
- 自訂的例外處理(Exception, try-catch) (4%)
- 資料即時更新 (避免同時借用的錯誤) (10%) 
- Report  必交，否則從已得分數中倒扣 10 分

## 架構

