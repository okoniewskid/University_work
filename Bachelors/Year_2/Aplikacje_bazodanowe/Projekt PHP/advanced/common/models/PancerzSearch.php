<?php

namespace common\models;

use Yii;
use yii\base\Model;
use yii\data\ActiveDataProvider;
use common\models\Pancerz;

/**
 * PancerzSearch represents the model behind the search form about `common\models\Pancerz`.
 */
class PancerzSearch extends Pancerz
{
    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['id', 'rodzaj_id', 'Obrona'], 'integer'],
            [['Nazwa'], 'safe'],
        ];
    }

    /**
     * @inheritdoc
     */
    public function scenarios()
    {
        // bypass scenarios() implementation in the parent class
        return Model::scenarios();
    }

    /**
     * Creates data provider instance with search query applied
     *
     * @param array $params
     *
     * @return ActiveDataProvider
     */
    public function search($params)
    {
        $query = Pancerz::find();

        $dataProvider = new ActiveDataProvider([
            'query' => $query,
        ]);

        $this->load($params);

        if (!$this->validate()) {
            // uncomment the following line if you do not want to any records when validation fails
            // $query->where('0=1');
            return $dataProvider;
        }

        $query->andFilterWhere([
            'id' => $this->id,
            'rodzaj_id' => $this->rodzaj_id,
            'Obrona' => $this->Obrona,
        ]);

        $query->andFilterWhere(['like', 'Nazwa', $this->Nazwa]);

        return $dataProvider;
    }
}
