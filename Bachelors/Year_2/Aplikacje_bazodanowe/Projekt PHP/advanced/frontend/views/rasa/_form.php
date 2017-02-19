<?php

use yii\helpers\Html;
use yii\widgets\ActiveForm;

/* @var $this yii\web\View */
/* @var $model common\models\Rasa */
/* @var $form yii\widgets\ActiveForm */
?>

<div class="rasa-form">

    <?php $form = ActiveForm::begin(); ?>

    <?= $form->field($model, 'Nazwa')->textInput(['maxlength' => 20]) ?>

    <?= $form->field($model, 'Zdolnosci')->textInput(['maxlength' => 200]) ?>

    <div class="form-group">
        <?= Html::submitButton($model->isNewRecord ? Yii::t('app', 'Stwórz') : Yii::t('app', 'Aktualizuj'), ['class' => $model->isNewRecord ? 'btn btn-success' : 'btn btn-primary']) ?>
    </div>

    <?php ActiveForm::end(); ?>

</div>
