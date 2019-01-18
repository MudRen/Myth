//shubao.c, updated 5-7-97, pickle

inherit NPC;
inherit F_MASTER;
string expell_me(object me);
void create()
{
  set_name("����", ({ "qin qiong", "qin", "shubao", "qiong", "qin shubao", "master", "shifu" }));
  set("title", "����Ԫѫ");
  set("gender", "����");
  set("age", 43);
  set("str", 30);
  set("per", 26);
  set("int", 30);
  set("long", "���屦�Ǵ��ƹ���������������һλ�������佫��\n");
  set("combat_exp", 1200000);
  set_skill("literate", 60);
  set_skill("spear", 120);
  set_skill("force", 150);
  set_skill("dodge", 200);
  set_skill("parry", 150);
  set_skill("yanxing-steps", 160);
  set_skill("bawang-qiang", 100);
  set_skill("lengquan-force", 150);
  set_skill("unarmed", 200);
  set_skill("changquan", 160);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 800);
  set("max_kee", 1400);
  set("force", 1000);
  set("max_force", 800);
  set("force_factor", 80);
  set("inquiry", ([
		   "תҵ": (: expell_me :),
		   "leave": (: expell_me :),
		   ]) );

  create_family("������", 2, "��");
  setup();
  carry_object("/d/obj/weapon/spear/yinqiang")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}

int accept_fight(object me)
{
        command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������\n");
        return 0;
}
void attempt_apprentice(object ob)
{
        command("haha");
	command("say �ܺã�ʱ����������֮��"+RANK_D->query_respect(ob)+"���Ŭ�������ձض��гɡ�\n");
        command("recruit " + ob->query("id") );
        return;
        }
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "fighter");
}
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="������") {
                me->set_temp("betray", 1);
		command("sigh");
                return ("���Ҵ����ɷ���ȴ���ܷ������Ը��(agree)?\n");
        }
        return ("ȥ����Ԭ�����ɣ�������֪����\n");
}
void init()
{
        add_action("do_agree", "agree");
}
int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
                command("say �����ȥ�ɣ������ն񣬺���Ϊ֮������\n");
                this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->set_temp("betray", 0);
                this_player()->save();
                return 1;
                }
        return 0;
}

