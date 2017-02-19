<?php

use yii\helpers\Html;

/* @var $this yii\web\View */
/* @var $model common\models\Rodzaj */

$this->title = Yii::t('app', 'Aktualizuj {modelClass}: ', [
    'modelClass' => 'rodzaj',
]) . ' ' . $model->Rodzaj;
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Rodzaje'), 'url' => ['index']];
$this->params['breadcrumbs'][] = ['label' => $model->Rodzaj, 'url' => ['view', 'id' => $model->id]];
$this->params['breadcrumbs'][] = Yii::t('app', 'Aktualizuj');
?>
<div class="rodzaj-update">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
