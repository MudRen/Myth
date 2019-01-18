//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string give_zui(object me);
void create()
{
       set_name(HIY"��ʮ����"NOR, ({"chun shisanniang", "chun", "shisanniang","niang"}));
       set("long",
"��˿�������µĴ���ӡ�����һֻ֩�뾫,����˿�����޳�����,���������յ�ȡ��˿�������¹ⱦ�϶�
����ʦ�ð׾����Ƴ�ˮ�𡣺ܶ���֮��,���и��ºŽ����һ����ӡ�\n");
       set("title", HIM"�һ�����"NOR);
       set("gender", "Ů��");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 22);
	set("int", 30);
       set("max_kee", 2900);
//       set("max_gin", 2600);
       set("max_sen", 2800);
       set("force", 1500);
       set("max_force", 1500);
       set("force_factor", 50);
       set("max_mana", 2000);
       set("mana", 3600);
       set("mana_factor", 100);
       set("combat_exp", 800000);
       set("daoxing", 800000);
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 100);
       set_skill("unarmed", 100);
       set_skill("dodge", 100);
       set_skill("force", 100);
       set_skill("parry", 100);
       set_skill("sword", 100);
       set_skill("spells", 100);
       set_skill("whip", 150);
   set_skill("pansi-dafa", 130);
   set_skill("lanhua-shou", 120);
   set_skill("jiuyin-xinjing", 100);
   set_skill("qingxia-jian", 150);
   set_skill("yueying-wubu", 100);
   set_skill("yinsuo-jinling", 150);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "qingxia-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
//   set("chat_chance_combat", 50);
   set("inquiry", ([
          		  "��������" : (: give_zui :),
]));
   set("chat_chance",5);
    set("chat_msg", ({
        HIG"��ʮ��������������:�һ���������ݲ�����\n"NOR,
        HIG"��ʮ��������������:����Ϊ������������һ�����ǲ����мɶ��ĵ�,��Ϊ��̫�����ˡ����ҳ�����ʱ��,����ʶһ����,������
��գ���ϲ���ڶ��߳�û���������и��ºŽ������ʥ������ʶ�������꣬��˿�����һ����ú�����\n"HIC,
        HIG"��ʮ��������������:�ҽд���ʮ��,�ҵ�ְҵ�����˽���鷳,���ǰ�������ɱ�ˣ�\n"NOR,
		HIG"��ʮ��������������:�Դ��뿪��˿��֮����ȥ�����ɳĮ���Һ���֪��ɳĮ�����ʲô���߹���������ʵʲôҲû�У�����
ɳĮ����ɳĮ�������ǿ�ʼ����һ����������������У�ֻ�г�ޣ�ֻ��ɱ�˺ͱ�ɱ��\n"NOR,
		HIG"��ʮ��������������:��ʵ��������ֻ������һ̳��ˮ����Խ��֪���Լ��ǲ����Ѿ����ǵ�ʱ���㷴���ǵ�Խ�����\n"NOR,
		HIG"��ʮ��������������:�Ǹ����ߵĵ���һֱ�����ꡣÿ�����꣬�Ҿͻ�����������һֱ�������Լ���������\n"NOR,
        }));

create_family("��˿��", 2, "����");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/obj/weapon/whip/whip")->wield();
	carry_object("/d/pansi/obj/qin");
}

void attempt_apprentice(object ob)
{
 if ( (string)ob->query("family/family_name")=="��˿��") {
   if (((int)ob->query("daoxing") < 100000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ������������˿��������\n");
       command("recruit " + ob->query("id") );
           ob->set("title", HIM"��˿���һ��������µ���"NOR);
	   ob->set("class", "yaomo");
   return;
   }
}

string give_zui(object me)
{
	me=this_player();
	me->set_temp("need_zui", 1);
	return "��������ֻ������̳��ˮ,�������Ҫ��?(yes)��\n";
}

void init()
{
	add_action("do_yes", "yes");
}
int do_yes(string arg)
{
	object me;

	me=this_player();
	
	if(me->query_temp("need_zui")) 
	{
		message_vision("$N�������Ҫ��\n\n", me);
		if( query("no_zui") == 0 )
		{
			message_vision("��ʮ����˵�����ã����Ҹ�����ɣ�\n", me);
			me->set_temp("need_zui", 0);

			carry_object("/d/pansi/obj/zui");
			command("give zui to " + me->query("id"));
			set("no_zui", 1);
			call_out("regenerate", 480);
		}
		else
		{
			message_vision("��ʮ����˵����һ̳��ˮ����,��ô��ô������Ҫ,���Ѿ����˱��ˡ�\n", me);
		}

		return 1;
	}
	return 0;
}

int regenerate()
{
	set("no_zui", 0);
	return 1;
}

