//cheng yaojin, updated 5/7/97, pickle

inherit NPC;
inherit F_MASTER;

string gloat();
string ask_me();

void create()
{
  set_name("��ҧ��", ({ "cheng yaojin", "cheng", "yaojin", "master", "shifu" }));
  set("title", "����Ԫѫ");
  set("gender", "����");
  set("age", 45);
  set("str", 30);
  set("per", 10);
  set("cor", 70);
  set("cps", 15);
  set("long","
��ҧ���Ǵ��ƿ��������ĸ�������������ѧ��һ��������ƥ��
�������������������ݵ���һ����졣̸�����ĸ����������
������Ľ��
");
  set("combat_exp", 800000);
  set("daoxing", 200000);

  set_skill("unarmed", 100);
  set_skill("force", 90);
  set_skill("lengquan-force", 50);
  set_skill("axe", 100);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("sanban-axe", 120);
  set_skill("spells", 40);
  set_skill("baguazhou", 40);
  set_skill("yanxing-steps", 40);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  set_temp("apply/armor", 10);
  set("max_sen", 300);
  set("max_kee", 2800);
  set("force", 500); 
  set("max_force", 500);
  set("force_factor", 40);
  set("max_mana", 200);
  set("mana", 200);
  set("mana_factor", 10);
  set("inquiry", ([
	"name"     : "�Ҿ����˳Ƹ����ĳ�ҧ��",
	"here"     : "�����Ǵ��ƹ�����������",
	"rumors"   : "�㿴�ϳ����ǳ���Ա��˳ŵĴ���С����Ϣ��ô��",
	"����"     : (: gloat :),
	"�׷�����" : "�ǰ׷��������Ҷ�ʦ����������������Ե��",
	"��Ե"     : (: ask_me :),
]) );

  create_family("������", 2, "��");

  setup();
  carry_object("/d/obj/weapon/axe/huafu")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

string gloat()
{
    command("say �ٺ٣�����������ӵ��ϳ̵������ˣ�");
    command("say �ϳ������ľ��ǵ����ǰ׷��������д��Ҹ���������");
    return "��Ҫ����մ�ŵ��ϳ̵ĸ�������Ӧ�ð���Ϊʦ��";
}
string ask_me()
{
    command("hehe");
    command("say ��Ϊ��Ե���������ܽ�ס�ϳ�����������������Ե�ˡ�");
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
    string myname=me->name(), myrude=RANK_D->query_rude(me);

    if (!me->query_temp("pending/jjf/to_be_hit"))
	return 0;
    me->delete_temp("pending/jjf/to_be_hit");
    set("force", 2*query("max_force"));
    set("force_factor", 200);
    if (!(ob=query_temp("weapon"))
     || ob->query_temp("skill_type") != "axe")
    {
	destruct(ob);
	ob=new("/d/obj/weapon/axe/huafu");
	ob->move(npc);
	command("wield axe");
    }
    command("say �������е��ӣ�");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
	command("say �ٺ٣�"+myrude+"һ�һﶼ����ס�����ǻ�ȥ��������ɣ�");
	return 1;
    }
    command("say �����е���˼���ٿ���һ�У�");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
	command("say "+myrude+"�ܾ�ס��һ�����Ѿ��������ˣ�����Ϳ�������ڶ��������ܲ����ˣ�");
	return 1;
    }
    command("say ��Ȼͦ�����ϳ����һ");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
	command("say ����"+myrude+"��Ե�ݱ��ϳ�Ҳ�Ͳ�����ôһ�������");
	return 1;
    }
    me->add_temp("jjf/�׷���Ե", 1);
    command("say "+myname+"��Ȼ����Ե�ˡ�");
    command("say ��ȥ����ʦ���ɣ������������Լ����������еģ����ֻ����ǿ�����������");

    return 1;
}

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
�