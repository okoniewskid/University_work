<?php

use yii\helpers\Html;

/* @var $this yii\web\View */
/* @var $model common\models\Postac */

$this->title = Yii::t('app', 'Aktualizuj {modelClass}: ', [
    'modelClass' => 'postać',
]) . ' ' . $model->Imie;
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Postacie'), 'url' => ['index']];
$this->params['breadcrumbs'][] = ['label' => $model->Imie, 'url' => ['view', 'id' => $model->id]];
$this->params['breadcrumbs'][] = Yii::t('app', 'Aktualizuj');
?>
<div class="postac-update">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
        'rasy' => $rasy,
        'bronie' => $bronie,
        'pancerze' => $pancerze,
    ]) ?>

</div>
