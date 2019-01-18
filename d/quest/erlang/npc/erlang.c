// by mon

inherit NPC;

int say_mifa(object me);
int say_chumo(object me);
int say_qujing(object me);
int do_leave();

void create()
{
  set_name("�������", ({"er lang","erlang","er"}));
  set("gender", "����");
  set("age", 40);
  set("long", @LONG
�����Ǵ�����������ʥ����������ݴ��ǵ�����۵�����
˼���½磬����������ĺ��ӡ�ֻ������

  �����忡ò���ã���������Ŀ�й⡣
  ͷ����ɽ�ɷ�ñ����һ�쵭��ơ�

LONG
);
  set("combat_exp", 10000000);
  set("daoxing", 5000000);

  set("per", 100);
  set_skill("dodge", 200);
  set("max_sen",1000);
  set("max_gee",1000);
  set("max_gin",1000);
  set("force",1000);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",200);
  set_skill("spells",200);
  set_skill("stick",200);
  set("inquiry",([
    "�õ��ط�": (: say_mifa :) ,
    "�õ�": (: say_mifa :),
    "����": (: say_mifa :),
    "�ط�": (: say_mifa :),
    "join": (: say_mifa :),
    "��ħ": (: say_chumo :),
    "����": (: say_chumo :),
    "ȡ����": (: say_qujing :),
    "ȡ��": (: say_qujing :),
//    "leave": (: do_leave :),
//    "����": (: do_leave :),
  ]));
  set("chat_chance",2);
  set("chat_msg",({
    "�������������������֮����������ѧ���������ܵ�����õ��ط�������\n",
    "�������˵����ħ�����������ܵõ�����İ���\n",
    "���˵��������ȡ��֮����ʢ��ȡ�������˵���߻��ӣ��ɱϾ�������\n",
    "���˵�������ⷨ��Ҫ�ǲ��飬���������ҡ�\n",
  }));

  setup();

}

void init()
{ object me=this_player();
  ::init();
//  add_action("do_agree","agree");
//  add_action("do_listen","listen");
  me->delete_temp("pkgroup");

}

int say_mifa(object dummy)
{ object me=this_player();
  message_vision("��������ٺ�һЦ��˵��"
  +"�����ܹ�ɱ���������֮�ˣ��Կ���ȡ����У���Ϊ���С�\n"
  +"������Ҳ���Ϊ���˵�Ŀ�꣬ȷ�������Ѽ���\n",me);
// �������⣬����������(listen)��\n",me);
  me->set_temp("pkgroup/listen",1);
  return 1;
}

int say_chumo(object me)
{
  message_vision("�������˵����"
  +"������ħ��������֮������������֮�ط�������ĵ��п��Ǵ��кô���\n",me);
  return 1;
}

int say_qujing(object me)
{
  message_vision("�������˵����"
  +"��ȡ��֮���˽���ӻ�����������֮�ط���ɱ��ʳ֮�����������ǳ�ġ�\n",me);
  return 1;
}

int do_leave()
{
  object me=this_player();
  int gain,lose;

  if(!me->query("kill")) return 0;

//  gain=me->query("pkgroup/gain");
//  lose=me->query("pkgroup/lose");
//  if(gain==1 && lose==1) {
//    message_vision("���������$N����һ�ţ������"+
//      RANK_D->query_rude(me)+"��û�Թ�����֪���飿��\n",me);  
//  } else {
//    if(5*gain>4*lose) {
    if(me->query("PKS")) {
//      message_vision("���������$N˵��������в�����������˭˵���飡�����ˡ�\n",me);
        message_vision("���������$N˵��������ɱ���ˣ���Ҳ���ܻ������ˣ�����\n",
	  me);
    } else {
      message_vision("�����$N̾�˿��������ⲻ���õ�"+
        RANK_D->query_rude(me)+"�����߰ɣ���Ҳ�������ң�\n",me);
//      me->add("combat_exp",-me->query("pkgroup/join_bonus"));
//      if(me->query("combat_exp")<0) me->set("combat_exp",0);
      me->delete("kill");
      me->save();
    }
//  }
  return 1;
}

int do_listen(string arg)
{ object me=this_player();
  if(me->query("pkgroup/gain")) {
    write("�����������һ����û���㡣\n");
    return 1;
  }
  if(me->query_temp("pkgroup/listen")) {
   if(me->query_temp("pkgroup/paid")) {
     message_vision("$N��ǰ���˼����������$N��������˵��Щʲô��\n",me);
     write("�������˵���Ӵ��Ժ������ɱ��who -k����ʾ����ң���"
       +"\n�ܵõ����ǵ�һ���ֵ��У���Ȼ������Ҳ����ɱ���㣬��ͬ����(agree)��\n");
     me->set_temp("pkgroup/agree",1);
   } else {
     message_vision("������˴���ָ����$N��Ц������λ"
     +RANK_D->query_respect(me)
     +"��֪ʲô��������\n",me);
   }
   return 1;
  } else return 0;
}

int do_agree(string arg)
{  object me=this_player();
   int dx,dx1;

   if(me->query_temp("pkgroup/agree")) {
     message_vision("�����$N˵�����ã������Ϊ֮�ɣ�\n",me);
     me->delete_temp("pkgroup/agree");
     me->set("pkgroup/lose",1);
     me->set("pkgroup/gain",1);

     //temporary bonus for joining pk.
     if(!me->query("pkgroup_left")) {
     dx=me->query("combat_exp");
     dx1=220-dx;
     if(dx1>0) {
       me->set("combat_exp",220);
       me->set("pkgroup/join_bonus",dx1);
       write("��ĵ��������ˣ�\n");
     }
     }

     me->save();
     return 1;
   }
   return 0;
}

int accept_object (object who, object ob)
{
//  if((!ob)||ob->value()<100000) {
//    message_vision("���̧ͷ����$Nһ�ۣ�û˵ʲô��\n",who);
//    return 1;
//  } else {
    who->set_temp("pkgroup/paid",1);
    message_vision("�����$N���ͷ���⻹��ࡣ\n",who);
    return 1;
//  }
}


�