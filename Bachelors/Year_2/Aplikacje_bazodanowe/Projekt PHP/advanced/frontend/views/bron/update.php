<?php

use yii\helpers\Html;

/* @var $this yii\web\View */
/* @var $model common\models\Bron */

$this->title = Yii::t('app', 'Aktualizuj {modelClass}: ', [
    'modelClass' => 'broń',
]) . ' ' . $model->Nazwa;
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Bronie'), 'url' => ['index']];
$this->params['breadcrumbs'][] = ['label' => $model->Nazwa, 'url' => ['view', 'id' => $model->id]];
$this->params['breadcrumbs'][] = Yii::t('app', 'Aktualizuj');
?>
<div class="bron-update">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
        'rodzaje' => $rodzaje,
        'obrazenia' => $obrazenia,
    ]) ?>

</div>
