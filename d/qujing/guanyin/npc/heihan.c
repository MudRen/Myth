// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
int give_good(object who);
int give_bad(object who);
int test_player (object who);
void create()
{
   set_name("�ں�", ({ "hei han", "han" }));
   set("title", "�ڷ綴����");   
   set("long", @LONG
�ں�����ɽ��Ұ�ޣ���֪������ѧ��һ��ñ��졣
�������Ϻ����������Ϻ�������Ϊͽ�ܡ�
LONG);
   set("gender", "����");
   set("age", 30);
   set("attitude", "heroism");
   set("per", 9);
   set("max_kee", 850);
   set("max_gin", 800);
   set("max_sen", 850);
   set("force", 400);
   set("max_force", 500);
   set("force_factor", 50);
   set("max_mana", 250);
   set("mana", 300);
   set("mana_factor", 20);
   set("combat_exp", 30000);
   set_skill("literate", 50);
   set_skill("spells", 160);
   set_skill("buddhism", 160);
   set_skill("unarmed", 200);
   set_skill("jienan-zhi", 195);
   set_skill("dodge", 180);
   set_skill("lotusmove", 180);
   set_skill("parry", 185);
   set_skill("force", 190);
   set_skill("lotusforce", 190);
   set_skill("staff", 160);
   set_skill("lunhui-zhang", 150);
   set_skill("spear", 160);
   set_skill("huoyun-qiang", 150);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   map_skill("spear", "huoyun-qiang");

   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jingang" :),
     (: cast_spell, "yinshen" :),
   }) );
   setup();
   carry_object("/d/qujing/guanyin/obj/boots")->wear();
   carry_object("/d/qujing/guanyin/obj/head")->wear();
   carry_object("/d/qujing/guanyin/obj/heilvshi")->wear();
   carry_object("/d/qujing/guanyin/obj/kaijia")->wear();
   carry_object("/d/qujing/guanyin/obj/zaopao")->wear();
   carry_object("/d/qujing/guanyin/obj/zaoying")->wield();
}
int accept_object (object who, object ob)
{
  object me = this_object();
  string msg = "�ں�˵������λ"+RANK_D->query_respect(who);

  if (test_player (who)){
  if ((ob->query("id") != "panzi")||(ob->query("guanyin")!="true"))
  {
	tell_object (who,msg+"���������Ĳ���������ô����ö���ƭ�Ұ����������������ˡ�\n");
	return 1;
  }
  if ((who)&&(who->query_temp("obstacle/guanyin_lingxuzi")))
  {
     if(random(3) < 1 ){
	call_out("give_bad",2,this_player());
	return 1;
     }
  }
  call_out("give_good",2,this_player());
  return 1;
  }else{
	tell_object (who,"�ں�ŭ����������ô������ģ����������������ķ��ϣ�����һ���Ͽ�����ӹ�Զ�㣡\n");
	return 1;
  }
}
int test_player (object who)
{
  string *names;
  string name;
  names = who->query_temp("apply/name");
  if (! names)
    return 0;
  if (sizeof(names) < 1)
    return 0;
  name = names[0];
  if (name == "������")
    return 1;
  return 0;
}
int give_good(object who)
{
  object me = this_object();
  message_vision ("$N�ӹ����ӣ���$n������л��\n",me,who);
  message_vision("$N���ɵ��������ʵ����У���ɫͻȻת�̣�һ�µ����ڵأ�\n", me);
  message_vision("����һ��$Nͷ��ð����������������������ȵ�վ��������\n", me);
  tell_object (who,"�ں�Ц�����Ժ�����Ⱥû���������հ����Ǻǡ�\n");
  return 1;
}
int give_bad(object who)
{
  object me = this_object();
  message_vision ("$N�ӹ����ӣ����ɵؿ���$n��\n",me,who);
  message_vision("$N�������ɵ�������ߣ������ͷ��������ɫͻȻת�ϣ���ž���ذѸ��ɵ�������飡\n", me);
  tell_object (who,"�ں���ɫһ�������ߣ���ҩ������мٰɣ�\n");
  who->set_temp("obstacle/guanyin_ask","xiandan");
  call_out("autokill",1,this_player(),this_object());
  return 1;
}
void autokill (object me, object who)
{
  message_vision ("$n˵�գ���¶�׹⣬����$N��\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
}
void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  
  if ((ob)&&(ob->query_temp("obstacle/guanyin_lingxuzi"))&&(ob->query_temp("obstacle/guanyin_ask")=="xiandan"))
  {
    ob->set_temp("obstacle/guanyin_heihan",1);
    call_out ("pusa_appearing",1,ob);
  }
  message_vision ("\nͻȻ���������������������顣\n",me);
  message_vision ("\n���������ó�����������$Nͷ�ϡ�\n",me);
  message_vision ("\n$N���ڵ����ֳ�ԭ�Σ�ԭ����һֻ���ܹ֡�\n",me);
  message_vision ("\n�������������˹ֵ�����Щ�۸���������ȥ�������ô�����ȼ�����ȥ�ɡ�\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/qujing/guanyin/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}
void unconcious ()
{
  die ();
}
int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}
void destruct_me(object me)
{
	if(me)
	destruct(me);
}
