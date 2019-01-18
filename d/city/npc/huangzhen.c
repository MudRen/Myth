/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Last modified by waiwai@2002/12/13 

inherit NPC;

#include <ansi.h>

int do_join(string arg);
int do_unjoin(string arg);
int do_yao();
int do_decide();

void create()
{
        set_name("����", ({"huang zhen", "zhen", "huang"}));
        set("title", "�̻��ܹ�");
        set("nickname", WHT"ͭ��������"NOR);
        set("gender", "����");
        set("age", 59);
        set("long",
                "�����ǳ������������ʷ�������Ҳ�����Ǯׯ��"
		"�ϰ壬���������á�\n");
        set("attitude", "peaceful");

        set("inquiry", ([
                "����" : "����������Լ���(join)��ҵЭ�ᡣ\n",
                "��ҵЭ��" : "���޺�Ʋ���������ҹ�ݲ��ʣ�������ҵЭ�ᣬ�����µ�һ���̲���������������Ŀ�ꡣ\n",
        ]));

        set("per", 21);
        set("str", 26);
        set("con", 30);
        set("spi", 30);
        set("int", 30);

	set("max_sen", 5000);
	set("max_kee", 5000);
	set("force", 6000);
	set("max_force", 3000);
	set("force_factor", 150);
	set("mana", 6000);
	set("max_mana", 3000);
	set("mana_factor", 100);

       set("combat_exp", 5000000);
       set("shen_type", 1);
       set("limit_fight", 1);//����fight
       set("no_kill", 1);//����kill
	set("no_blade", 1);//���±���
	set("no_poison", 1);//�����ö�

	set_skill("literate", 160);
	set_skill("spear", 160);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("mace", 150);
	set_skill("archery", 200);
	set_skill("wusi-mace", 180);
	set_skill("yanxing-steps", 150);
	set_skill("bawang-qiang", 180);
	set_skill("lengquan-force", 180);
	set_skill("unarmed", 150);
	set_skill("changquan", 150);
	set_skill("spells", 150);
	set_skill("baguazhou", 150);

	map_skill("spells", "baguazhou");
	map_skill("mace", "wusi-mace");
	map_skill("force", "lengquan-force");
	map_skill("unarmed", "changquan");
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "bawang-qiang");
	map_skill("dodge", "yanxing-steps");

	set("chat_chance",3);
	set("chat_msg", ({
	    name()+"˵��������������Լ���(join)��ҵЭ�ᣡ\n",
	    name()+"˵�������޺�Ʋ���������ҹ�ݲ��ʣ�������ҵЭ�ᣬ�����µ�һ���̲���������������Ŀ�꣡\n",
		    }));

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "spear", "qiangjian" :),
       	(: perform_action, "spear", "hui" :),
	       (: perform_action, "spear", "shou" :),
	}) );

	setup();
	carry_object("/d/obj/weapon/spear/tieqiang")->wield();
	carry_object("/d/obj/armor/tiejia")->wear();
	carry_object("/d/obj/weapon/mace/copperjian");
}

void init()
{
        add_action("do_join","join");
        add_action("do_decide","decide");
        add_action("do_yao","yao");
        add_action("do_unjoin","unjoin");
        delete_temp("busy");
}

int do_join(string arg)
{
        object me;
        me = this_player();
        if (!arg || arg != "��ҵЭ��") 
		return notify_fail("������ֵĶ���˵������Ҫ����ʲô������������ҵЭ�ᡣ��\n");

        if (me->query("is_vendor")) 
		return notify_fail("������ֵĶ���˵�������Ѿ��������˰�����\n");

        if (me->query("bad_vendor") && !wizardp(me))  
		return notify_fail(HIY"����̾Ϣ���������ȥ��Ȼ�Ѿ���������ҵЭ�ᣬ���ھͲ�Ҫ���뵱�����ˣ���\n"NOR);

        tell_object(me,HIY"��������Ķ���˵����һ����ֻ����"HIR"һ�λ���"HIY"������ҵЭ�ᣬ���Ҫ�ú����룬����(decide)�ٸ����ҡ���\n");
        me->set_temp("want_join",1);
        return 1;
}

int do_unjoin(string arg)
{
        object me;
        me = this_player();

        if (!arg || arg != "��ҵЭ��") 
		return notify_fail(HIG"������ֵĶ���˵������Ҫ����ʲô������������ҵЭ�ᡣ��\n"NOR);

        if (!me->query("is_vendor") )
		return notify_fail(HIG"������ֵĶ���˵���������ڲ����������˰�����\n"NOR);

        tell_object(me,HIY"��������Ķ���˵������һ������������ҵЭ�ᣬ����Զ���ܵ������ˣ����Ҫ�ú����룬����(decide)�ٸ����ҡ���\n"NOR);
        me->set_temp("want_tuoli",1);
        return 1;
}

int do_decide()
{
	 object ob,me;
        me = this_player();
        if (me->query_temp("want_join")) {
                message_vision(HIY"$N����$n���ͷ���ܺã�Ǯ������֮��������������ף���úøɣ����ճ���ͷ�أ�\n"+NOR,this_object(),me);
                me->set("is_vendor",1);
                me->delete_temp("want_join");
                ob = new("/d/obj/misc/zhizhao");
                ob->move(me);
                message_vision(HIY"$N��һ��"NOR + ob->name(1) + HIY"�䷢��$n��\n"NOR,this_object(),me);
                return 1;
         }
        if (me->query_temp("want_tuoli")) {
                message_vision(HIY"$N����$n���ͷ���ðɣ��˸���־���Ӵ��Ժ��������޹ϸ�\n"NOR,this_object(),me);
                me->delete("is_vendor");
                me->set("bad_vendor",1);
                me->delete_temp("want_tuoli");
                if (ob = present("shangye zhizhao",me));
                message_vision(HIY"$N��$n��"NOR + ob->name(1) + HIY"ע���ˡ�\n"NOR,this_object(),me);
                destruct(ob);
                return 1;
         }
         return notify_fail("���澪�ȵ��ʣ�����Ҫ����ʲôѽ����\n");
}

int do_yao()
{
        object ob,me = this_player();

        if (!me->query("is_vendor")) 
		return notify_fail("����Ц�Ŷ���˵�������ֲ������ˣ�����������Ҫʲô��Ҫ������\n");

        if (present("shangye zhizhao",me)) 
		return notify_fail("����������Ʋ��Ʋ�죺����ҵִ�ղ��Ǻúõ��������ϣ���ô��������Ҫ����\n");

        if (HEIDIAN_D->is_owner(me->query("id"))) 
		return notify_fail("����Ǻ�Ц��˵�����������Ǵ��ϰ壬��Ҫʲô��ҵִ���أ���\n");

        ob = new("/d/obj/misc/zhizhao");
        ob->move(me);
        message_vision(HIY"$N��һ��"NOR + ob->name(1) + HIY"������$n��\n"NOR,this_object(),me);
        return 1;
}
