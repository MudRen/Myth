// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
string ask_me();

void create()
{
          set_name("�������", ({"lao yuanzhu", "yuanzhu"}));
          set("gender", "����");
          set("title", "��Ժ��");
          set("long", "����Ժ�����֡�\n");
          set("attitude", "heroism");
          set("class", "yaomo");
          set("bellicosity", 800);
          set("per", 18);
          set("age", 270);
          set("str", 25);
          set("looking", "�������ƣ�һ˫���ۣ��������䣬���ձ�����\n");
          set("combat_exp", 1200000);
          set_skill("unarmed", 175);
          set_skill("dodge", 175);
          set_skill("blade", 175);
          set_skill("parry", 175);
          set_skill("force", 175);
          set_skill("spells", 175);
          set_skill("moshenbu", 175);
          set_skill("cuixin-zhang", 175);
          map_skill("unarmed", "cuixin-zhang");
          map_skill("parry", "cuixin-zhang");
          map_skill("dodge", "moshenbu");
          set("force", 700);
        set("max_force", 700);
        set("force_factor", 30);
        set("max_kee", 800);
        set("max_sen", 800);
        set("max_mana", 300);
        set("mana", 300);
  set("chat_chance",10);
  set("chat_msg",({
         "��Ժ�������ֹ���������һ����ϲ������...\n",
  }));
	set("inquiry", ([
		"����"     : (: ask_me :),
	]) );
   set("mana_factor", 20);
   set_temp("apply/armor", 25);
   setup();
   carry_object("/d/qujing/guanyin/obj/jinshan")->wear();
   carry_object("/d/qujing/guanyin/obj/sengpao")->wear();
   carry_object("/d/qujing/guanyin/obj/guaizhang")->wield();
}
string ask_me()
{
	if(this_player()->query("obstacle/guanyin")!="done"){
		this_player()->set_temp("obstacle/guanyin_ask","ok");
		call_out("autokill",1,this_player(),this_object());
		return "�ߣ���ôû�����㣿������û�ˣ�Ҫ������һ���������ҽ��Ҳ�������...";
	}else{
		return "�ҿɲ���Ҫ��������ˡ�";
	}	
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
void unconcious()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  if ((ob) && (ob->query_temp("obstacle/guanyin_ask") == "ok"))
  {
	ob->set_temp("obstacle/guanyin_yuanzhu",1);
	message_vision("\n��Ժ��ͻȻת��һͷ��ǽ��ײȥ...\n",me);
	message_vision("����ֻײ������Ѫ������ɢ���ʺ�����Ⱦ��ɳ��\n" ,me);
	message_vision("$N��ѽһ��������������\n\n",me);
  }else{
	message_vision("$Nһ�������Ե��ڵأ����ˡ�\n\n",me);
  }
  message_vision("һ��紵������Ժ����ʬ���ʱ�����ҽ���\n\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",1,me);
}
void destruct_me(object me)
{
	if(me)
	destruct(me);
}
void die()
{
  unconcious();
}
