<?php

use yii\helpers\Html;
use yii\widgets\DetailView;

/* @var $this yii\web\View */
/* @var $model common\models\Postac */

$this->title = $model->Imie;
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Postacie'), 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="postac-view">

    <h1><?= Html::encode($this->title) ?></h1>

    <p>
        <?= Html::a(Yii::t('app', 'Aktualizuj'), ['update', 'id' => $model->id], ['class' => 'btn btn-primary']) ?>
        <?= Html::a(Yii::t('app', 'Usuń'), ['delete', 'id' => $model->id], [
            'class' => 'btn btn-danger',
            'data' => [
                'confirm' => Yii::t('app', 'Na pewno usunąć?'),
                'method' => 'post',
            ],
        ]) ?>
    </p>

    <?= DetailView::widget([
        'model' => $model,
        'attributes' => [
            'id',
            'rasa.Nazwa:text:Rasa',
            'Imie:text:Imię',
            'Wiek',
            'Wzrost:decimal',
            'Waga:decimal',
            'Zloto:currency:Złoto',
            'bron.Nazwa:text:Broń',
            'pancerz.Nazwa:text:Pancerz',
            'Data_utworzenia:date',
        ],
    ]) ?>

</div>
