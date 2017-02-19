<?php

use yii\helpers\Html;
use yii\widgets\ActiveForm;

/* @var $this yii\web\View */
/* @var $model common\models\Postac */
/* @var $form yii\widgets\ActiveForm */
?>

<div class="postac-form">

    <?php $form = ActiveForm::begin(); ?>

    <?= $form->field($model, 'rasa_id')->dropDownList($rasy)->label('Rasa') ?>

    <?= $form->field($model, 'Imie')->textInput(['maxlength' => 45]) ?>

    <?= $form->field($model, 'Wiek')->textInput() ?>

    <?= $form->field($model, 'Wzrost')->textInput(['maxlength' => 5]) ?>

    <?= $form->field($model, 'Waga')->textInput(['maxlength' => 5]) ?>

    <?= $form->field($model, 'Zloto')->textInput(['maxlength' => 5]) ?>

    <?= $form->field($model, 'bron_id')->dropDownList($bronie)->label('Broń') ?>

    <?= $form->field($model, 'pancerz_id')->dropDownList($pancerze)->label('Pancerz') ?>

    <?= $form->field($model, 'Data_utworzenia')->textInput() ?>

    <div class="form-group">
        <?= Html::submitButton($model->isNewRecord ? Yii::t('app', 'Stwórz') : Yii::t('app', 'Aktualizuj'), ['class' => $model->isNewRecord ? 'btn btn-success' : 'btn btn-primary']) ?>
    </div>

    <?php ActiveForm::end(); ?>

</div>
