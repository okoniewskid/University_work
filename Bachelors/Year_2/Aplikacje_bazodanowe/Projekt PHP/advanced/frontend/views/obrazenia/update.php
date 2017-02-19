<?php

use yii\helpers\Html;

/* @var $this yii\web\View */
/* @var $model common\models\Obrazenia */

$this->title = Yii::t('app', 'Aktualizuj {modelClass}: ', [
    'modelClass' => 'obrażenia',
]) . ' ' . $model->Obrazenia;
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Obrażenia'), 'url' => ['index']];
$this->params['breadcrumbs'][] = ['label' => $model->Obrazenia, 'url' => ['view', 'id' => $model->id]];
$this->params['breadcrumbs'][] = Yii::t('app', 'Aktualizuj');
?>
<div class="obrazenia-update">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
