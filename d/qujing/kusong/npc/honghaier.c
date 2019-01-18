//Cracked by Roath
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_niang(object me);
int do_yes();

int rank_me();

void create()
{
       set_name("�캢��", ({"honghai er","er"}));
	set("title", "ʥӤ����");
	set("long", "ţħ������ɲŮ�Ķ��ӣ��ڻ���ɽ��������һ��ñ��졣\n");
       set("gender", "����");
       set("age", 16);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("spi", 25);

       	set("attitude", "heroism");

        set("combat_exp", 1200000);
  set("daoxing", 1500000);

        set("eff_dx", -500000);
        set("nkgain", 500);

       	set("class","yaomo");
       	set("max_kee", 1600);
       	set("max_sen", 1600);
       	set("force", 2500);
       	set("max_force", 1600);
       	set("force_factor", 100);
       	set("max_mana", 1600);
       	set("mana", 2500);
       	set("mana_factor", 80);
       
	set_skill("unarmed", 150);
       	set_skill("dodge", 200);
       	set_skill("force", 150);
       	set_skill("parry", 150);
       	set_skill("spear", 180);
	set_skill("spells", 150);
 	set_skill("huoyun-qiang", 180);
	set_skill("moshenbu", 200);
	set_skill("moyun-shou", 150);
	set_skill("huomoforce", 180);
	set_skill("pingtian-dafa", 150);

	map_skill("force", "huomoforce");
	map_skill("spells", "pingtian-dafa");
	map_skill("unarmed", "moyun-shou");
	map_skill("dodge", "moshenbu");
	map_skill("parry", "huoyun-qiang");
	map_skill("spear", "huoyun-qiang");

	set("kusong/Teach_Hong", 1);
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: cast_spell, "sanmei" :),
	}));


	create_family("���ƶ�", 2, "��");

        set("inquiry", ([
                "ְλ": (: rank_me :),
                "���ȹ���": (: ask_niang :),
]) );


        setup();
        carry_object("/d/nanhai/obj/huojianqiang")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}

void attempt_apprentice(object ob)
{       ob=this_player();

	if( (string)ob->query("family/family_name") == "���ƶ�") {

		if( (int)ob->query("max_mana") > 200 
		&& (int)ob->query("max_force") > 200
		&& !(int)ob->query("kusong") ) {
	
		command("nod");
		command("recruit " + ob->query("id"));
		return ;
		}
	}
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
		ob->set("title", "���ɽ����ƶ�С��");
		ob->set("kusong/Teach_Hong", 1);
	}
}


int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
        if( me->query("title") == "���ɽ�����ɽ�̲�̶��ɽ�ܶ���")
		return notify_fail("���Ѿ�����ɽ�ܶ����ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "���ƶ�"
	&& (string)me->query("family/master_id") == "honghai er"){

		
		if( exp <= 10000 ){
			me->set("title", "���ɽ����ƶ�ѲɽС��");
		} else if(exp <= 50000 ){
			me->set("title", "���ɽ����ƶ��ȷ�");
		} else if(exp < 100000 ){
			me->set("title", "���ɽ����ƶ�����");
		} else if(exp <= 250000 ){
			me->set("title", "���ɽ����ƶ�Ѳɽ��");
		} else if(exp <= 500000 ){
			me->set("title", "���ɽ����ƶ�����");
		} else if(exp <= 1000000 ){
			me->set("title", "���ɽ����ƶ�ħ��");
		} else if(exp <= 1500000 ){
			me->set("title", "���ɽ����ƶ�����");
		} else {
			me->set("title", "���ɽ����ƶ�����");
		}

		tell_object(me, "�캢������˵���������"+me->query("title")+"��\n");
		tell_room(environment(me),
"�캢����"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
	}
	return 1;
}
void init()
{
        object ob = this_player();
        remove_call_out("check");
        call_out("check",1,ob);
        add_action("do_yes","ok");
}

void check(object ob)
{
        object where;
        if (!ob) return;
        where=environment(ob);
        if(ob->query("family/family_name") == "���ƶ�")
           return;
        if(ob->query("title") == "��ͨ����")
           return;
        if(ob->query_temp("kusong_killed") == 1)
           return;
        if ( ob->query_temp("apply/id") 
        && member_array("niumo",ob->query_temp("apply/id") ) )
           {
        command("say �������л���������������");
        command("say ��������ץ��һ�����У������������Գ������ϰ���");
        command("xixi");
        return;
            }

        if( present("jin che",where) || present("mu che",where)
        ||  present("shui che",where) || present("huo che",where) ||
            present("tu che",where) )
          {
if (userp(ob)) {
        kill_ob(ob);
        message_vision(HIR"ֻ���캢���ּ����г������л��ǹ��$Nһָ��\n"NOR,ob);
        message_vision(HIR"һ������������Ũ������$N��$N������ߡ�\n"NOR,ob);
        ob->move("/d/qujing/kusong/guaishiya");
        ob->unconcious();
        }
}

}
int ask_niang(object me)
{
       me=this_player();
       command("jump");
       me->set_temp("ok",1);
       command("say ��ȥ������һ��������ok����\n");
       return 1;
}

int do_yes()
{
        object ob = this_player();
        if( ! ob->query_temp("ok") ) return 0;
        command("say �������ڼҵȺ򣬺�����ȥ��ء�");
        command("bye");
        destruct(this_object());
        return 1;
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void announce_success (object who)
{
  int i;
  object honghaier= this_object();

  if (! who->query_temp("che1_broken"))
   {
    destruct (honghaier);
    return;
   } 
  if (! who->query_temp("che2_broken"))
   {
    destruct (honghaier);
    return;
   } 
  if (! who->query_temp("che3_broken"))
   {
    destruct (honghaier);
    return;
   } 
  if (! who->query_temp("che4_broken"))
   {
    destruct (honghaier);
    return;  
   } 
  if (! who->query_temp("che5_broken"))
   {
    destruct (honghaier);
    return;  
   } 
  honghaier->move(environment(who));
  who->set_temp("kusong_killed",1);
  message_vision (HIR"һ�ź�ɫ������ӿ�˹���,�캢��ͻȻ��������˳���.\n"NOR,who);
  message_vision (HIG"$N����"HIR+"���ǹ"HIG+"��$nһָ:�󵨳���,���ƻ��ҵ����г�.\n"NOR,honghaier,who);
  message_vision (HIG"ֻ��һ��$Nŭ��:�Ҿ�˵������ô��������.����������.\n"NOR,honghaier,who);
  who->command("bian");
  kill_ob(who);
}  
void die()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  if (ob->query_temp("obstacle/hong_killed")) return ;
  if (ob)
  {
    ob->set_temp("obstacle/hong_killed",1);
    call_out ("pusa_appearing",1,ob);
  }
  message_vision(HIY"���ϴ��������������������캢�����������һ��Ϻ�ȥ��\n"NOR,ob);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}
void destruct_me (object me)
{
  destruct (me);
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/qujing/kusong/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}


void unconcious ()
{
  die();
}
