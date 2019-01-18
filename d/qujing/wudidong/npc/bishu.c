// bishu.c ����
// 9-2-97 pickle

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

/************************************************************/

// function and global variable declaractions

int attempt_apprentice(object me);
int recruit_apprentice(object me);
int prevent_learn(object me, string skill);
int accept_object(object me, object ob);
void bishu_leave(object me);
/************************************************************/

void create()
{
  set_name("����", ({"bi shu", "bi", "shu", "bishu", "monster"}));
  set("gender", "Ů��");
  set("age", 19);
  set("long",
"��Ȼ���������������磬����˵���츳���ѣ��ǿ����ɵĺ����ӡ�\n"
"�Դ����޵׶������������书�������죬���иϹ�����ļ�ʽ��\n");
  set("title", "�޵׶������");
  set("nickname", HIR"����һ��"NOR);
  set("combat_exp", 800000);
  set("daoxing", 1500000);

  set("attitude", "heroic");
  create_family("�ݿ�ɽ�޵׶�", 2, "����");
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("stealing", 150);
  set_skill("spells", 100);
  set_skill("sword", 30);
  set_skill("qixiu-jian", 30);
  set_skill("yinfeng-zhua", 30);
  set_skill("lingfu-steps", 100);
  set_skill("force", 100);
  set_skill("blade", 100);
  set_skill("kugu-blade", 100);
  set_skill("yaofa", 30);
  set_skill("huntian-qigong", 30);
  map_skill("force", "huntian-qigong");
  map_skill("blade", "kugu-blade");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spells", "yaofa");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  
  set("cor", 50);
  set("str", 30);
  set("per", 30);
  set("max_kee", 900);
  set("max_sen", 900);
  set("force", 650);
  set("max_force", 650);
  set("force_factor", 20);
  set("mana", 650);
  set("max_mana", 600);
  set("mana_factor", 25);
  set("inquiry", ([
                   "name": "��������ǵ�ӿ���˵Ŀ�ɽ����ӣ�",
                   "here": "��Ϲ��������������Ƕ����������ݿ�ɽ�޵׶���",
		   "rumors": "��֪�����ұ�����ȥ��",
		   "�������": "��Ϲ���������������ֲ��ǳ��ӣ�",
                 ]) );  

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
  if (me->query("combat_exp")+me->query("daoxing")<200000)
  {
    command("say "+myname+"��ʲô�ã�����ô�㱾�»���������������Ь��");
    return 1;
  }
  if (me->query("wudidong/sell_reward") < 5000)
  {
    command("say "+myname+"���û�����������ˣ����������������Ӷ��ȷ��ˣ�");
    command("say ��ȥ�������͵��������⣡��ʱ�򱾹���һ���ˣ�˵�������������ˡ�");
    return 1;
  }
  command("grin");
  command("say �����������������ˡ�"+myname+"�����˶������Ū��ԭ�ϣ�");
  command("recruit "+myid);
  return 1;
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_rude(me);

  if(skill == "kugu-blade")
  { 
    message_vision(CYN"����ŭ����û�Ŷ������̣�\n", me);
    return 1;
  }
  return 0;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}
/************************************************************/

int accept_object(object me, object ob)
{
    if (ob->query("name_recognized") != "�׹���")
	return notify_fail(CYN"����ŭ�������ʣ����ֲ��������õģ�\n"NOR);
    remove_call_out("bishu_leave");
    call_out("bishu_leave", 1, me);
    return 1;
}
void bishu_leave(object me)
{
    command("say �⡢�⡢�⣬�����ô���Ǻã�");
    command("sigh");
    command("say ��Ȼ���������ڴˣ��һ��ǸϽ���ȥһ�˰ɣ�");
    message_vision("����ץ��һ�����������һ�ף��������ߣ�������ȥ�ˡ�\n", me);
    destruct(this_object());
    return;
}
�
