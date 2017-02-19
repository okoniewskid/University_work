<?php

namespace common\models;

use Yii;

/**
 * This is the model class for table "rasa".
 *
 * @property integer $id
 * @property string $Nazwa
 * @property string $Zdolnosci
 *
 * @property Postac[] $postacs
 */
class Rasa extends \yii\db\ActiveRecord
{
    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'rasa';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['Nazwa', 'Zdolnosci'], 'required'],
            [['Nazwa'], 'string', 'max' => 20],
            [['Zdolnosci'], 'string', 'max' => 200]
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => Yii::t('app', 'ID'),
            'Nazwa' => Yii::t('app', 'Nazwa'),
            'Zdolnosci' => Yii::t('app', 'Zdolnosci'),
        ];
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getPostacs()
    {
        return $this->hasMany(Postac::className(), ['rasa_id' => 'id']);
    }
}
