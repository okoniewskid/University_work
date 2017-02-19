<?php

namespace common\models;

use Yii;
use yii\base\Model;
use yii\data\ActiveDataProvider;
use common\models\Postac;

/**
 * PostacSearch represents the model behind the search form about `common\models\Postac`.
 */
class PostacSearch extends Postac
{
    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['id', 'rasa_id', 'Wiek', 'bron_id', 'pancerz_id'], 'integer'],
            [['Imie', 'Data_utworzenia'], 'safe'],
            [['Wzrost', 'Waga', 'Zloto'], 'number'],
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
        $query = Postac::find();

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
            'rasa_id' => $this->rasa_id,
            'Wiek' => $this->Wiek,
            'Wzrost' => $this->Wzrost,
            'Waga' => $this->Waga,
            'Zloto' => $this->Zloto,
            'bron_id' => $this->bron_id,
            'pancerz_id' => $this->pancerz_id,
            'Data_utworzenia' => $this->Data_utworzenia,
        ]);

        $query->andFilterWhere(['like', 'Imie', $this->Imie]);

        return $dataProvider;
    }
}
