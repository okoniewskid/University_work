<?php

use yii\helpers\Html;

/* @var $this yii\web\View */
/* @var $model common\models\Rasa */

$this->title = Yii::t('app', 'Aktualizuj {modelClass}: ', [
    'modelClass' => 'rasę',
]) . ' ' . $model->Nazwa;
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Rasy'), 'url' => ['index']];
$this->params['breadcrumbs'][] = ['label' => $model->Nazwa, 'url' => ['view', 'id' => $model->id]];
$this->params['breadcrumbs'][] = Yii::t('app', 'Aktualizuj');
?>
<div class="rasa-update">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
