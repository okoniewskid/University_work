<?php

namespace common\models;

use Yii;
use yii\base\Model;
use yii\data\ActiveDataProvider;
use common\models\Bron;

/**
 * BronSearch represents the model behind the search form about `common\models\Bron`.
 */
class BronSearch extends Bron
{
    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['id', 'rodzaj_id', 'obrazenia_id'], 'integer'],
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
        $query = Bron::find();

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
            'obrazenia_id' => $this->obrazenia_id,
        ]);

        $query->andFilterWhere(['like', 'Nazwa', $this->Nazwa]);

        return $dataProvider;
    }
}
