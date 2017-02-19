<?php

use yii\helpers\Html;
use yii\grid\GridView;

/* @var $this yii\web\View */
/* @var $searchModel common\models\PostacSearch */
/* @var $dataProvider yii\data\ActiveDataProvider */

$this->title = Yii::t('app', 'Postacie');
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="postac-index">

    <h1><?= Html::encode($this->title) ?></h1>
    <?php // echo $this->render('_search', ['model' => $searchModel]); ?>

    <p>
        <?= Html::a(Yii::t('app', 'Stwórz postać'), ['create'], ['class' => 'btn btn-success']) ?>
    </p>

    <?= GridView::widget([
        'dataProvider' => $dataProvider,
        'filterModel' => $searchModel,
        'columns' => [
            ['class' => 'yii\grid\SerialColumn'],

          //  'id',
            'rasa.Nazwa:text:Rasa',
            'Imie:text:Imię',
            'Wiek',
            'Wzrost:decimal',
            'Waga:decimal',
            'Zloto:currency:Złoto',
            'bron.Nazwa:text:Broń',
            'pancerz.Nazwa:text:Pancerz',
            'Data_utworzenia:date',

            ['class' => 'yii\grid\ActionColumn'],
        ],
    ]); ?>

</div>
