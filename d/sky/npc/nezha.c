// created 4/12/1998 by bbs
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
  set_name("��߸", ({ "nezha santaizi", "nezha", "santaizi" }));
  set("title", "��̳����֮��");
  create_family("�ݿ�ɽ�޵׶�", 1, "����");
  set("class", "xian");
  set("long", "һλ����ݰ׵������ꡣ\n");
  set("gender", "����");
  set("age", 16);
  set("attitude", "heroism");
  set("rank_info/respect", "С̫��");
  set("rank_info/rude", "���δ�ɵ�С��");
  set("per", 40);
  set("str", 30);
  set("cor", 40);
  set("con", 40);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("kar", 40);
  set("max_kee", 2000);
  set("max_gin", 1800);
  set("max_sen", 3000);
  set("force", 2600);
  set("max_force", 4000);
  set("force_factor", 100);
  set("max_mana", 3000);
  set("mana", 5000);
  set("mana_factor", 120);
  set("combat_exp", 1500000);
  set("daoxing", 2000000);

  set_skill("spells", 180);
  set_skill("dao", 180);
  set_skill("unarmed", 170);
  set_skill("yinfeng-zhua", 180);
  set_skill("dodge", 180);
  set_skill("lingfu-steps", 170);
  set_skill("parry", 190);
  set_skill("force", 190);
  set_skill("huntian-qigong", 180);
  set_skill("spear", 170);
  set_skill("huoyun-qiang", 150);
  set_skill("blade", 170);
  set_skill("sword", 200);
  set_skill("qixiu-jian", 180);
  map_skill("spells", "dao");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spear", "huoyun-qiang");
  map_skill("parry", "huoyun-qiang");
  map_skill("sword", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  map_skill("force", "huntian-qigong");
  set("inquiry", ([
	"name": "��������������̫������߸��Ҳ��",
	"here": "������������������",
	"rumors": "���뷷����Ϊ��ħ��Ԫ˧������Ϊ��̳����֮��ר�ܽ�����ħ��",
	"����": "�޵׶������󾫣������ҵ�����Ů��",
	"���ǹ": "�����ˣ�",
	]));
  setup();
  carry_object("/d/obj/cloth/taijicloth")->wear();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/sword/qingfeng")->wield();
  if ("/d/obj/fabao/huntian-ling"->in_mud())
    carry_object("/d/obj/fabao/huntian-fake");
  else
    carry_object("/d/obj/fabao/huntian-ling");
  if ("/d/obj/fabao/qiankun-quan"->in_mud())
    carry_object("/d/obj/fabao/qiankun-fake");
  else
    carry_object("/d/obj/fabao/qiankun-quan");
}

void attempt_apprentice(object ob)
{
  if ((string)ob->query("family/family_name")=="�ݿ�ɽ�޵׶�") {
	if(ob->query("obstacle/wudidong")=="done") {
		command("say ��ʵ�书������а֮�֣���Ҫ���������ƶ�");
		command("say "+RANK_D->query_respect(ob)+"��Ȼ�������ƣ����������ӵķ��ϣ���������ɡ�");
		command("recruit "+ob->query("id"));
	}
	else {
		command("say "+RANK_D->query_respect(ob)+"���޵׶��ĵ��ӣ����Ҳ�����ʰɣ�");
		command("say "+RANK_D->query_respect(ob)+"��Ը��ѧ�����������ӵķ��ϣ��ҵ����Ե㲦һ����");
	}
  }
  else {
  	command("say �Ҳ���ʶ�㡣");
	command("sorry");
  }
}

int prevent_learn(object me, string skill)
{
  int myyaofa=me->query_skill("yaofa",1);

  if (skill == "dao") {
	if(myyaofa!=0) {
		command("sigh");
		command("say "+RANK_D->query_respect(me)+"����̫�أ�����ѧ�����ɷ���");
		return 1;
	}
  }
  return 0;
}

void die()
{
  int i;
  object *inv;
  string msg;

  if(environment()) {
    msg="$N�޺޵ص���Сү�����ȥ����״�����������������ţ�\n";
    msg+="$N������⣬���������ŷ����ȥ��\n\n";
    message_vision(msg, this_object(), this_player());
    inv=all_inventory(this_object());
    for(i=0; i<sizeof(inv); i++) {
      if (inv[i]->query("no_drop")) continue;
      do_drop(this_object(), inv[i]);
    }
  }
  destruct(this_object());
}

int do_drop(object me, object obj) 
{
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
            else {
                 message_vision( sprintf("$N����һ%s$n��\n", undefinedp(obj->query_temp("unit"))? "��":obj->query_temp("unit") ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
           else {
             message_vision( sprintf("$N����һ%s$n��\n", obj->query("unit")), me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}

void unconcious()
{
    die();
}
�