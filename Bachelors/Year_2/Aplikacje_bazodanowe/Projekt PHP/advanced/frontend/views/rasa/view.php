<?php

use yii\helpers\Html;
use yii\widgets\DetailView;

/* @var $this yii\web\View */
/* @var $model common\models\Rasa */

$this->title = $model->Nazwa;
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Rasy'), 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="rasa-view">

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
            'Nazwa',
            'Zdolnosci:text:Zdolności',
        ],
    ]) ?>

</div>
