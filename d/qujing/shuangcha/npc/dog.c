//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// dog.c

inherit NPC;

void create()
{
   set_name("���ǹ�", ({ "dog" }) );
   set("race", "Ұ��");
   set("age", 3);
   set("long", "һֻ���ú����͵��ǹ���\n");
   
   set("str", 32);
   set("dex", 36);

   set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 6);
   set("chat_msg", ({
     (: call_other, this_object(), "random_move" :),
     "���ǹ����������ҽС�\n",
     "���ǹ��ú���ץ��ץ�Լ��Ķ��䡣\n" }) );
     
   set_temp("apply/attack", 10);
   set_temp("apply/armor", 3);

   setup();
}

int accept_object(object who, object ob)
{
   if( ob->id("bone") ) {
     set_leader(who);
     message("vision", name() + "���˵���������������\n", environment());
     return 1;
   }
}
