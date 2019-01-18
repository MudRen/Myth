//Cracked by Roath
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
  set_name("�����", ({"jiru huo","huo"}));
  set("gender", "����");
  set("age", 10);
  set("title", "���ƶ�����");
  set("long","һ����ü���۵�С������\n");
  set("combat_exp", 100000+random(3000));
  set("daoxing", 100000);

  set("per", 15);

  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("unarmed", 60);
  set_skill("force", 60);
  set_skill("spells", 60);
  set_skill("pingtian-dafa", 40);
  set_skill("huomoforce", 40);
  set_skill("moyun-shou", 40);
  set_skill("moshenbu", 40);
  set_skill("fork", 60);
  set_skill("spear", 60);
  set_skill("stick", 60);
   set_skill("dali-bang",60);
  map_skill("force", "huomoforce");
  map_skill("spells", "pingtian-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("dodge", "moshenbu");

  set("max_sen",800);
  set("max_kee",800);

  set("force", 400);
  set("max_force", 400);
  set("force_factor", 20);
  set("mana", 400);
  set("max_mana", 400);
  set("mana_factor", 20);

        set("inquiry", ([
                "��ɽ": (: expell_me :),
                "leave": (: expell_me :),
]) );

  create_family("���ƶ�", 3, "��");

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

void attempt_apprentice(object ob)
{       ob=this_player();

        if( (string)ob->query("family/family_name") == "���ƶ�") {
		command("say ���ͬ�����ˣ����ҵ������ҵ���\n");
		return;
	}
                command("grin");
                command("recruit " + ob->query("id"));
                return ;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
                ob->set("title", "���ɽ����ƶ�С��");
        }
}

string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="���ƶ�") {
                me->set_temp("hyd_betray", 2);
                return ("��Ҫ��ɽ������ɽ��ͷ����ҽ�������ɽ����ѧ���죬���Ը��(agree)?");
        }
        return ("��֪��");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
      if(this_player()->query_temp("hyd_betray") > 1 &&
                  this_player()->query("family/family_name")=="���ƶ�") {
                message_vision("$N�����Ը�⡣\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/huoyun", 1);
                this_player()->add("combat_exp", -(this_player()->query("combat_exp")/20));
                    this_player()->delete_skill("dali-bang");
                    this_player()->delete_skill("huomoforce");
                    this_player()->delete_skill("moshenbu");
                    this_player()->delete_skill("moyun-shou");
                    this_player()->delete_skill("pingtian-dafa");
                    this_player()->delete_skill("yueya-chan");
                    this_player()->delete_skill("wuyue-spear");
                    this_player()->delete_skill("huoyun-qiang");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->delete_temp("hyd_betray");
                this_player()->set("title", "��ͨ����");
                this_player()->save();
                command("say ����ȥ�ɣ�\n");
                return 1;
                }
        return 0;
}

�
