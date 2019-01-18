//��ԯ��ĹNPC ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string say_key();
void punish_player(object me);
int accept_object(object me, object ob);

/************************************************************/
void create()
{
  set_name(HIW"������" NOR, ({"wang guiren", "wang", "guiren"}));
    set_weight(1000000);
  set("gender", "Ů��" );
  set("age", 23);
   set("long", "
��槼�һͬ������ɽ������һֻʯ���þ���������ǳ��ȴ����ס������
���ʮɫ����˷��������������ջ󣬶���ħ�������ڳ��豻����ռ��
��ʿ��̫������������һ�Ǵ���������˷���̨������槼�һͬ����
\n");
  set("title", HIB"��ʯ���þ�" NOR);
  set("combat_exp", 10000000);
  set("attitude", "heroic");
  create_family("��ԯ��Ĺ", 1, "����");
  set("int", 25+random(5));
  set("cor", 30+random(10));
  set("per", 40);
  set_skill("unarmed", 220);
  set_skill("dodge", 220);
  set_skill("mace", 220);
  set_skill("parry", 220);
  set_skill("spells", 220); 
  set_skill("youming-spells", 220);
  set_skill("yinlei-mace", 220);
  set_skill("sword",220);
  set_skill("qinghu-jian",220);
  set_skill("blade", 220);
  set_skill("zizhi-blade", 220);
  set_skill("kongming-steps", 220);
  set_skill("jiuyin-zhua", 220);
  set_skill("force", 220);   
  set_skill("jiuyin-force", 220);
  map_skill("force", "jiuyin-force");
  map_skill("spells", "youming-spells");
  map_skill("unarmed", "jiuyin-zhua");
  map_skill("sword", "qinghu-jian");
  map_skill("parry", "zizhi-blade");
  map_skill("blade", "qinghu-blade");
  map_skill("dodge", "kongming--steps");
  map_skill("mace", "yinlei-mace");
  set("per", 50);
  set("max_kee", 5000);
  set("max_sen", 5000);
  set("force", 6000);
  set("max_force", 3000);
  set("force_factor", 150);
  set("mana",6000);
  set("max_mana", 3000);
  set("mana_factor", 150);
  set("inquiry",([
       "name": "�Ҿ����������ˣ���Ҫ���ң�",
       "here": "���������ԯ��Ĺ������ʯ�����������Ұ���ߣ����ֲ����㣡",
       ]));
  set("chat_chance_combat", 60);
   
   set("chat_msg_combat", ({
    (: perform_action, "sword.hebi" :)
   }) );
  setup();
  carry_object("/d/obj/weapon/sword/xy_sword.c")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
}
/**************************************************************/

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
if(me->query("family/master_id") != "da ji" && me->query("family/master_id") != "xi mei")
  {
      command("say ʲô������Ҳ�����Ϊʦ��");
      return 1;
  }
else  if (me->query_skill("jiuyin-force", 1) < 50 || me->query("combat_exp") < 200000)
  {
    command("say "+me->name()+"��������ƾ�ǵ㱾�»����䣡");
    return 1;
  }
else if (me->query_temp("gumu/kill")!="done") {
  command("bite");
  command("say �����һ����ǡ�"+myname+"ȥ�����������ˣ���Ҫ���������");
return 1;
}
  command("recruit "+myid);
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}


int prevent_learn(object me, string skill)
{
  int myyinlei=me->query_skill("yilei-mace", 1);
  if (wizardp(me) && me->query("env/immortal"))
    return 0;
  if (skill == "yinlei-mace")
  {
      if (myyinlei>=200)
      {
   command("say �㻹��ȥ����ɱ���Ǹ�����ͷ�ӣ���С���������㣡");
   return 1;
      }
if (myyinlei<=1 && me->query_temp("gumu/kill")) return 0;
  if (myyinlei>1 && me->query_temp("gumu/kill")) return 0;
//      if (myyinlei141 && me-query("gumu/given_book_2")) return 0;
//      if (myyinlei=81 && me-query("gumu/given_book_1")) return 0;
      command("say ���̣��������Դ���ѧ��");
      return 1;

    }
if (skill == "youming-spell" && me->query("gumu/kill")=="done")
  {
      call_out("punish_player", 1, me);
      return 1;
  }
  return 0;
}
int accept_object(object me, object ob)
{
        object nowords;
        if(userp(ob)) return 0;
        if( (string)ob->query("name")=="�����" )
        {
                command("thank " + me->query("id"));
   command("say �ţ���Ȼ�Ǵ���ޡ����Ե�����ŵ�ԣ�����Ϊͽ��");
         command("recruit "+me->query("id")); 
      me->set_temp("gumu/kill","done");
    return 1;
}
        else
{
            command("say ����ҵ�����ʲô����������������");
            return 1;
}
}

