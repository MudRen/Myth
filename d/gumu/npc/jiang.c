inherit NPC;
#include <ansi.h>
string gloat();
string ask_me();

void create()
{
  set_name("������", ({ "jiang ziya", "jiang" }));
  set("title", HIW"���������"NOR);
  set("nickname", HIR"̫����"NOR  );
  set("gender", "����");
  set("age", 65);
  set("str", 100);
  set("per", 100);
  set("cor", 100);
  set("cps", 100);
  set("long","�����ǵ������̨��һͳ�����̫������������");
  set("combat_exp", 3000000);
  set("daoxing", 2000000);

 set("family/family/name", "��ԯ��Ĺ"); 
  set_skill("unarmed", 100);
  set_skill("force", 250);
  set_skill("jiuyin-force", 250);
  set_skill("mace", 300);
  set_skill("dodge", 300);
  set_skill("parry", 300);
  set_skill("spells", 80);
  set_skill("yinlei-mace", 250);
  set_skill("youming-spells", 40);
  set_skill("kongming-steps", 240);
  map_skill("force", "jiuyin-force");
  map_skill("spells", "youming-spells");
  map_skill("mace", "yinlei-mace");
  map_skill("parry", "yinlei-mace");
  map_skill("dodge", "kongming-steps");
  set_temp("apply/armor", 600);
    set_temp("apply/damage", 350); 
    set_temp("apply/dodge", 350); 
  set("max_sen", 3000);
  set("max_kee", 5000);
  set("force", 3000); 
  set("max_force", 3000);
  set("force_factor", 250);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 500);
  set("inquiry", ([
        "name"     : "�Ϸ���ǽ�������",
        "������"     : (: gloat :),
        "�����"     : (: ask_me :),
]) );


  setup();
  carry_object("/d/obj/weapon/whip/longsuo")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

string gloat()
{
    command("say �����Ϸ��������裬�������Ѿ�֪�����ǳ��ࡣ");
    command("say ��˵����槼��ӷ���̨�ܳ����ˣ�������");
    return "���ҪС�ģ���Ҫ�����������Ի󰡡�";
}
string ask_me()
{
    command("smile");
    command("say �����Ϸ�Ĵ���ޣ���Ȼ�Ǻ�����η����");
    command("haha");
    command("say ֻҪ���ܽ������ޣ��ұ㽫�����������㡣");
    this_player()->add_temp("pending/jjf/to_be_hit", 1);
    return "���Ը��һ�ԣ�(yuanyi)";
}

void init()
{
    ::init();

    add_action("do_agree", "yuanyi");
    add_action("do_agree", "agree");
}

int do_agree(string arg)
{
    object me=this_player(), npc=this_object(), ob;
           object mace;
    string myname=me->name(), myrude=RANK_D->query_rude(me);

    if (!me->query_temp("pending/jjf/to_be_hit"))
        return 0;
    me->delete_temp("pending/jjf/to_be_hit");
    set("force", 2*query("max_force"));
    set("force_factor", 250);
    if (!(ob=query_temp("weapon"))
     || ob->query_temp("skill_type") != "whip")
    {
        destruct(ob);
        ob=new("/d/obj/weapon/whip/longsuo");
        ob->move(npc);
        command("wield whip");
    }
    command("say �ã��е�ʶ�������˵�һ��");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
        command("say ����"+myrude+"һ�¶�����ס�����ǻ�ȥ��������ɣ�");
        return 1;
    }
    command("say ��������ڶ���");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
        command("say "+myrude+"�ܾ�ס������һ�����Ѿ��������ˣ���ĸ��ǲ�������Ŭ������");
        return 1;
    }
    command("say �ã��ܰ����Ǵ���ޣ���������");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
        command("say ����"+myrude+"��Ϊ���ˣ���ȥ���˰ɡ�");
        return 1;
    }
    command("say "+myname+"�������ǳ���������ǰ�˰��������ˣ�����������");
    command("say  �� ���˹�Ȼ���������ұ㽫�����������㣬�мɲ�Ҫ�����캦������鰡���������춨������
��");
    mace=new("/d/wizz/junhyun/obj/mace.c"); 
   mace->move(me);
    return 1;
}
/*
int accept_fight(object me)
{
  command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������");
  return 0;
}

void attempt_apprentice(object me)
{
  int effstr=(int)(me->query("str"));
  int myuna=me->query_skill("unarmed", 1)/10-2;
  string myrude=RANK_D->query_rude(me);

  if (myuna < 0) myuna=0;
  effstr+=myuna;
  if (effstr<30)
    {
      command("say "+myrude+"��㾢��ֻ���϶������������ո�ͷ��");
      return 0;
    }
  if (me->query_cor()<30)
    {
      command("say "+myrude+"����Ѫ�������������˵��������գ�");
      return 0;
    }
  command("ah");
  command("say �벻�����ϳ�������è����Ҳ����ͽ��\n");
  command("recruit " + me->query("id") );
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
  if (skill =="spells" || skill == "baguazhou")
    {
      command("say �Ϸ��Լ�Ҳ�㲻�����ô���£������ܽ����أ�");
//      return notify_fail("�����ӳ�ҧ������ѧ����������ˡ�");
      return 1;
    }
  return 0;
}

*/

