<?php

use yii\helpers\Html;
use yii\widgets\ActiveForm;

/* @var $this yii\web\View */
/* @var $model common\models\Pancerz */
/* @var $form yii\widgets\ActiveForm */
?>

<div class="pancerz-form">

    <?php $form = ActiveForm::begin(); ?>

    <?= $form->field($model, 'Nazwa')->textInput(['maxlength' => 20]) ?>

    <?= $form->field($model, 'rodzaj_id')->dropDownList($rodzaje)->label('Rodzaj obrony') ?>

    <?= $form->field($model, 'Obrona')->textInput() ?>

    <div class="form-group">
        <?= Html::submitButton($model->isNewRecord ? Yii::t('app', 'Stwórz') : Yii::t('app', 'Aktualizuj'), ['class' => $model->isNewRecord ? 'btn btn-success' : 'btn btn-primary']) ?>
    </div>

    <?php ActiveForm::end(); ?>

</div>
