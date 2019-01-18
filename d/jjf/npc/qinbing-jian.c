//created 6-9-97 pickle
//�ױ�

#include <ansi.h>
inherit NPC;
string ask_me(object me);

void create()
{
  set_name("�ױ�", ({"qin bing", "qin", "bing", "soldier", "qinbing"}));
  set ("long", @LONG
һ�����δ󺺣��������·�����ǽ������ױ������Ǹ���
��������Ԫ���Ľ������������˱�����Ԫ�����ƺ�����
��ɢǮ�ƳԺȡ�
LONG); 
  set("title", "������");
  set("gender", "����");
  set("age", 25);
  set("combat_exp", 80000);
  set_skill("blade", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("wuhu-blade", 60);
  map_skill("blade", "wuhu-blade");
  set("max_sen", 200);
  set("max_kee", 300);
  set("inquiry", ([
        "name" : "��ʲô�ʣ������۾����ῴ�ģ�",
        "here" : "�����������¥����Ŀɱȶ������Ʒ���ǿ�ö�����",
        "rumors" : " ��˵�����������ӣ��ߣ�",
        "ʳ��" : "��������񣬿�����Щ����ȥ��",
        "Ǯ��" : "��������񣬿�����Щ����ȥ��",
        "����" : (: ask_me :),
        "baozi" : (: ask_me :),
        "����" : (: ask_me :),
        "silver" : (: ask_me :),
        "����" : "�ߣ����ǰ����Ӵ��ˣ�����˭Ҳ�����������Ұ��",
         ]) );
  setup();
 
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/cloth/bingfu")->wear();
}
int accept_object(object me, object ob)
{
  object npc=this_object();
 
  if ((string)ob->query("name_recognized")!="�������")
    {
      command ("say ��������������˻����ˣ�");
      call_out("destroy", 1, ob);
      return 1;
    }
  call_out("leavehere", 1, npc, me);
  return 1;
}
string ask_me(object me)
{
  return("���Դ��������쵽(ling)���ӻ����ӡ�");
}
void init()
{
  add_action("do_ling", "ling");
}
int do_ling(string arg)
{
  object me=this_player(), npc=this_object(),ob;
  int kar=me->query_kar(), diff=kar-10;
  string player=me->query("id");

  if (!arg || (arg != "baozi" && arg != "����" && arg != "silver" && arg!="����"))
    return notify_fail("����Ҫʲô��\n");
  if ((string)me->query("family/family_name") == "������")
    {
       me->add_temp("jjf/����¥Ҫ����", 1);
       switch(me->query_temp("jjf/����¥Ҫ����"))
         {
           case(1):
             {
                command("slap "+player);
                command("say ߾����λ��ү��޵ľ��ǽ��������ӣ����ҹ���");
                message_vision(CYN"�ױ�����һ������$Nƨ���ϣ���$N�߳����⡣\n"NOR, me);
                me->move("/d/city/center");
                return 1;
             }
           case(2):
             {
                command("slap "+player);
                command("say ĪҪ���Ʋ��ԳԷ��ƣ�����һ�οɱ�����Ӳ������ˣ�");
                message_vision(CYN "�ױ�����һ������$Nƨ���ϣ���$N�߳����⡣\n" NOR, me);
                me->move("/d/city/center");
                return 1;
            }
           default:
             {
                command("say �����㣡���ӿ���ʵ�ڲ�˳�ۣ�ȥ���ɣ�");
                kill_ob(me);
                return 1;
            }
          } 
   }
  if ((string)me->query("title") != "����ƽ��") 
    {
      command("sneer "+player);
      command("say ���ʣ��б��µ��Լ��ɻ�ȥ��");
      return 1;
    }
  if (arg == "baozi" || arg == "����")
    {
      if (me->query("kee") < 40 || me->query("sen") < 40)
	return notify_fail("��̫���ˣ��������ױ����ϡ����������ò����ˡ�\n");
      ob=new("/d/obj/food/baozi");
      ob->move(npc);
      command("say �ðɣ�����������Ӱɣ���������˭����ĺô���");
      me->receive_damage("kee", 40-kar);
      me->receive_damage("sen", 40-kar);
      message_vision("$N�Ѿ���ţ����֮���������û�����ʹ���Ŵ���Ⱥ�м����ױ���ǰ��\n",me);
      command("give bao to "+player);
      return 1;
    }
  if (diff < 5)
    {
      command("slap "+player);
      command("say ���ӿ�������"+RANK_D->query_rude(me)+"�Ͳ�˳�ۣ�����û��ķݣ�");
      return 1;
    }
  if (me->query("kee") < 60 || me->query("sen") < 60)
    return notify_fail("��̫���ˣ��������ױ����ϡ����������ò����ˡ�\n");

  if( (int)npc->query("time") > 10 ) 
    return notify_fail("�ױ�һ���֣�˵����������ӷ����ˣ����������ɡ�\n");


  npc->add_money("silver", 2*(int)diff/5);
  command("say �ðɣ���������Ǯ������������˭����ĺô���");
  npc->add("time", 1);
  me->receive_damage("kee", (40-kar)*2);
  me->receive_damage("sen", (40-kar)*2);
  message_vision("$N�Ѿ���ţ����֮���������û�����ʹ���Ŵ���Ⱥ�м����ױ���ǰ��\n",me);
  command("give silver to "+player);
  return 1;
}
void leavehere(object npc, object me)
{
  command("ah");
  command("say ��Ȼ�����м��£������ȥ�죡");
  command("thank "+me->query("id"));
  command("go northwest");
  destruct(npc);
  return;
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
