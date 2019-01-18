//created 8-5-97 pickle
//�޳� luocheng.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int handle_kill(object me);
int accept_fight(object me);
int attempt_apprentice(object me);
int recruit_apprentice(object me);
void check_fight (object npc, object me);
void player_win(object me);
void player_lose(object me);
void move_down(object ob);
void do_revive(object ob);

void create()
{
  set_name("�޳�", ({"luo cheng", "luo", "cheng", "luocheng", "master", "shifu"}));
  set ("long", @LONG
�޳�������ı�ܣ��������Ƶ������ú�����˵������
�ڱ�����ʱ���Ҽ�����ս��������֪Ϊ�λ��������
˵�޳�����ʱ���ܹ����˴��ڣ�ѧ��һ��������ڹ���
��˱��伫�ٰܹ���
LONG);

  set("title", "����Ԫѫ");
  set("gender", "����");
  set("age", 34);
  set("str", 50);
  set("cor", 50);
  set("cps", 50);
  set("spi", 30);
  set("per", 30);
  set("con", 50);
  set("int", 30);
  set("kar", 15);
  set("combat_exp", 1800000);
  set_skill("literate", 220);
  set_skill("force", 220);
  set_skill("lengquan-force", 220);
  set_skill("parry", 220);
  set_skill("spells", 220);
  set_skill("baguazhou", 220);
  set_skill("dodge", 220);
  set_skill("yanxing-steps", 220);
  set_skill("unarmed", 220);
  set_skill("changquan", 220);
  set_skill("mace", 220);
  set_skill("wusi-mace", 220);
  set_skill("spear", 220);
  set_skill("bawang-qiang", 220);
  map_skill("mace", "wusi-mace");
  map_skill("force", "lengquan-force");
   map_skill("unarmed", "changquan");
   map_skill("spells", "baguazhou");
  map_skill("parry", "bawang-qiang");
  map_skill("spear", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 3000);
  set("max_kee", 3600);
  set("force", 2000);
  set("max_force", 2000);
  set("force_factor", 100);
 
  create_family("������", 2, "��");
  setup();
 
  carry_object("/d/jjf/obj/longqiang.c")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && member_array(ob, query_enemy()) != -1)
	{
	    if (is_fighting())
	    {
		message_vision(CYN"�޳ɶ�$N�ȵ����������㣡����ȥ����"NOR, ob);
		move_down(ob);
	    }
	    else do_revive(this_object());
	}
	add_action("do_kill", "kill");
        add_action("do_surrender", "surrender");
}
int do_surrender()
{
    this_player()->delete_temp("pending/jjf_apprentice_luocheng");
    return 0;
}
int do_kill(string arg)
{
    if(!id(arg)) return 0;
    handle_kill(this_player());
    return 0;
}
int handle_kill(object me)
{
    if(is_fighting())
    {
        message_vision(CYN"�޳ɱ�ȭ������λ����Ȼ$N��Ҫƴ���������Ժ�Ƭ�̡�\n"NOR, me);
        this_object()->remove_all_enemy();
    }
    do_revive(this_object());
    command("kill "+me->query("id"));
}
int accept_fight(object me)
{
  if(me->query_temp("pending/jjf_apprentice_luocheng"))
    {
      set("kee", query("max_kee"));
      set("force", query("max_force"));
      remove_call_out("check_fight");
      call_out("check_fight", 1, this_object(), me);
      return 1;
    }
  command("say �ѵ���������������ܣ��ҿ��������˰ɡ�\n");
  call_out("move_down", 1, me);
  return 0;
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);

  if(me->query("mark/jjf_defeated_luocheng")) 
  {
    command("say ��������"+myname+"��Ȼ�ǿɽ�֮�ţ�");
    command("say "+myname+"���չ��ˡ����Ҳ����д�һ����");
    command("recruit "+me->query("id"));
    return 1;
  }
  if (is_fighting())
  {
    command("say ����������æ��"+myname+"���Ժ�");
    return 1;
  }
  command("consider");
  command("say ���´Ӳ���ͽ��");
  command("say ����������ʤ��������ǹ�����Ҳ��������д蹦��");
  me->set_temp("pending/jjf_apprentice_luocheng", 1);
  return 1;
}
int chat()
{
    if(!is_fighting()) return 1;
    if(random(100)<30) do_revive(this_object());
}
void check_fight (object npc, object me)
{
  int npc_kee, my_kee, my_ratio, npc_ratio;
  int npc_max_kee, my_max_kee;
 
  my_kee = me->query("kee");
  npc_kee = npc->query("kee");
  my_max_kee = me->query("max_kee");
  npc_max_kee = npc->query("max_kee");
  my_ratio=my_kee*100/my_max_kee;
  npc_ratio=npc_kee*100/npc_max_kee;

  if (is_fighting())
  {
    call_out ("check_fight",2,npc,me);
    return;
  }
  if (query_temp("last_opponent")!=me) return;
  if (!present(me, environment(npc)))
    return;
  if(npc->query("kee")*100/npc->query("max_kee")
   < me->query("kee")*100/me->query("max_kee"))
    call_out("player_win", 1, me);
  else call_out("player_lose", 1, me);
  return;
}
void player_win(object me)
{
    this_object()->delete_temp("last_opponent");
    if (me->query_temp("pending/jjf_apprentice_luocheng"))
      {
	me->set("mark/jjf_defeated_luocheng", 1);
        me->delete_temp("pending/jjf_apprentice_luocheng");
	command("recruit "+me->query("id"));
      }
    return;
}
void player_lose(object me)
{
    this_object()->delete_temp("last_opponent");
    command("say "+RANK_D->query_respect(me) +"�������٣��ٽ�������");
    return;
}
int recruit_apprentice(object me)
{
  if( ::recruit_apprentice(me))
  {
    me->delete_temp("pending/jjf_apprentice_luocheng");
    me->delete("mark/jjf_defeated_luocheng");
    me->set("class", "fighter");
  }
}
void do_revive(object ob)
{
    int kee=ob->query("kee"), max_kee=ob->query("max_kee"), eff_kee=ob->query("eff_kee");
    int force=ob->query("force"), max_force=ob->query("max_force");
    int diff_force=max_force-force, diff_kee=max_kee-kee;
    if(diff_force<0) diff_force=0;
    if(diff_kee<0) diff_kee=0;
    ob->receive_curing("kee", diff_kee*2/3);
    ob->set("force", force+diff_force*2/3);
}
void move_down(object me)
{
    if(environment(this_object())!=find_object("/d/jjf/guest_cabinet2"))
      return;
    me->move("/d/jjf/guest_cabinet");
    return;
}
