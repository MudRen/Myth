/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
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
        set_name("黄真", ({"huang zhen", "zhen", "huang"}));
        set("title", "商会总管");
        set("nickname", WHT"铜笔铁算盘"NOR);
        set("gender", "男性");
        set("age", 59);
        set("long",
                "黄真是长安将军府的帐房先生，也是这个钱庄的"
		"老板，管理长安军饷。\n");
        set("attitude", "peaceful");

        set("inquiry", ([
                "加入" : "在我这里，可以加入(join)商业协会。\n",
                "商业协会" : "人无横财不富，马无夜草不肥，加入商业协会，当天下第一奸商才是人生最求的最好目标。\n",
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
       set("limit_fight", 1);//不能fight
       set("no_kill", 1);//不能kill
	set("no_blade", 1);//不怕冰刀
	set("no_poison", 1);//不怕用毒

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
	    name()+"说道：在我这里，可以加入(join)商业协会！\n",
	    name()+"说道：人无横财不富，马无夜草不肥，加入商业协会，当天下第一奸商才是人生最求的最好目标！\n",
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
        if (!arg || arg != "商业协会") 
		return notify_fail("黄真奇怪的对你说：“你要加入什么？我这里是商业协会。”\n");

        if (me->query("is_vendor")) 
		return notify_fail("黄真奇怪的对你说：“你已经是商人了啊！”\n");

        if (me->query("bad_vendor") && !wizardp(me))  
		return notify_fail(HIY"黄真叹息道：“你过去既然已经脱离了商业协会，现在就不要再想当商人了！”\n"NOR);

        tell_object(me,HIY"黄真认真的对你说：“一个人只能有"HIR"一次机会"HIY"加入商业协会，你可要好好想想，决定(decide)再告诉我。”\n");
        me->set_temp("want_join",1);
        return 1;
}

int do_unjoin(string arg)
{
        object me;
        me = this_player();

        if (!arg || arg != "商业协会") 
		return notify_fail(HIG"黄真奇怪的对你说：“你要脱离什么？我这里是商业协会。”\n"NOR);

        if (!me->query("is_vendor") )
		return notify_fail(HIG"黄真奇怪的对你说：“你现在并不是商人了啊！”\n"NOR);

        tell_object(me,HIY"黄真认真的对你说：“你一旦决定脱离商业协会，就永远不能当商人了，你可要好好想想，决定(decide)再告诉我。”\n"NOR);
        me->set_temp("want_tuoli",1);
        return 1;
}

int do_decide()
{
	 object ob,me;
        me = this_player();
        if (me->query_temp("want_join")) {
                message_vision(HIY"$N对着$n点点头，很好，钱乃万能之物，奸商是天下主宰，你好好干，早日出人头地！\n"+NOR,this_object(),me);
                me->set("is_vendor",1);
                me->delete_temp("want_join");
                ob = new("/d/obj/misc/zhizhao");
                ob->move(me);
                message_vision(HIY"$N将一份"NOR + ob->name(1) + HIY"颁发给$n。\n"NOR,this_object(),me);
                return 1;
         }
        if (me->query_temp("want_tuoli")) {
                message_vision(HIY"$N对着$n点点头，好吧，人各有志，从此以后你我再无瓜葛。\n"NOR,this_object(),me);
                me->delete("is_vendor");
                me->set("bad_vendor",1);
                me->delete_temp("want_tuoli");
                if (ob = present("shangye zhizhao",me));
                message_vision(HIY"$N将$n的"NOR + ob->name(1) + HIY"注销了。\n"NOR,this_object(),me);
                destruct(ob);
                return 1;
         }
         return notify_fail("黄真惊讶的问：“你要决定什么呀？”\n");
}

int do_yao()
{
        object ob,me = this_player();

        if (!me->query("is_vendor")) 
		return notify_fail("黄真笑着对你说：“你又不是商人，到我这里来要什么？要饭？”\n");

        if (present("shangye zhizhao",me)) 
		return notify_fail("黄真生气的撇了撇嘴：“商业执照不是好好的在你身上？怎么又来问我要？”\n");

        if (HEIDIAN_D->is_owner(me->query("id"))) 
		return notify_fail("黄真呵呵笑着说：“你现在是大老板，还要什么商业执照呢！”\n");

        ob = new("/d/obj/misc/zhizhao");
        ob->move(me);
        message_vision(HIY"$N将一份"NOR + ob->name(1) + HIY"补发给$n。\n"NOR,this_object(),me);
        return 1;
}
