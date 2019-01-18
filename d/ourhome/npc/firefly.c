// firefly.c by none 96/10/11

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ө���", ({ "firefly" }) );
	set("gender", "Ů��" );
	set("age", 7);
	set("long", "����һֻ�ɰ���ө��棬���������ȥΪ·��ָ·��
��һ˫�廨СЬ����������Ʒ�ɡ�\n");
	set("combat_exp", 10);
	set("str", 27);
	set("force", 30);
	set("max_force", 30);
	set("force_factor", 1);
	setup();
	set("chat_chance", 20);
	carry_object("/d/ourhome/obj/phone");
	add_money("coin", 5);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        set("chat_chance", 20);
        set("inquiry", ([
                "name" : "���Ǹ����������ҽ�ө��档���أ�^_*\n",
                "road" : "�����������зɴ�������ȥ�Ķ���\n",
		"·"   : "�����������зɴ�������ȥ�Ķ���\n",
                "here" : "���������������������ĵط��ɶ��ˡ�Ŷ�����ˣ�Ҫ��Ҫ��ȥ�ʾָ��������������������һ�£�֪��·��\n", 
		"�ʾ�" : "����С�긽����^_*\n",
		"��ҵ" : "���ң������ȥ�����ϰ尡:O\n",
		"����" : "��С��һֱ�����ߣ�ǧ��Ҫ�����߶����:P\n",
		"�ɴ�" : "����һ���أ���ϧ���Ὺ:(��Ὺ�ɴ��𣿴��ҷɺ���Һ�԰�ò��ã�\n",
      		"��԰" : "�ö�óԵ�ร�\n", 
		"����" : "�������Ǵ峤����\n",
		"ө���" : "Զ����ߣ�������ǰ��^_*\n",
		"С��" : "�㲻�Ǵ��Ƕ���������\n",
	 ]) );
        set("chat_msg_combat", ({
                "ө���޽е���ɱ���ģ�ɱ���ģ�\n",
                "ө���޽е����������ģ����컯���´���ģ�\n",
                (: command, "surrender" :),
        }) );

        set("chat_msg", ({
                "ө���Цӯӯ�ظ�·�ϵ��˴��к���\n",
                "ө���˵�����ҽ�ө��棬����˭ѽ��\n",
                "ө���߱ı߳���СƤ�򣬼ݽ��ߣ�����������ʮһ����\n",
                "ө���߳��߱ģ��������������ߣ����˶�����ʮһ����\n",
                (: random_move :)
        }) );

}

int accept_object(object me, object ob)
{
	object phone;

//    if ((string)ob->query("liquid/type")=="alcohol") {
//        if ((int)ob->query("liquid/remaining") == 0) {
     if ((string)ob->query("id")!="shoes") {
            command("smile");
            command("say ��ÿ���Ӵ^_*��");
	    command("give " + ob->query("id") + "to" + me->query("id"));
            return 1;
        }
        else {
		command("joythank " + me->query("id"));
       		command("say лл��λ" + RANK_D->query_respect(me) + "��:)");
	        command("give phone to " + me->query("id"));
	        carry_object("/d/ourhome/obj/phone");
       		return 1;
        }
}

int accept_fight(object me)
{

//	CHANNEL_D->do_channel("ө���", "chat", "cry", 1);	
	command("chat* " + "ө����뵽���Ĵ�, �̲�ס�������.\n");
	command("chat ����~~~��λ" + RANK_D->query_respect(me) + "����ร�:(\n");
	return 0;
}

void greeting(object ob)
{
//        if( !ob || environment(ob) != environment() ) return;
	if( !ob ) return;

        switch( random(5) ) {
                case 0:
                        tell_object( ob, GRN "ө������ĳ��ſ����Ķ�������˵���������:)\n" NOR);
			tell_room( environment(), "ө������ĳ��ſ��" + ob->name() + "����С����˵��Щ����\n", ({ ob, ob }) );
			break;
                case 1:
                        tell_object( ob, GRN "ө������ĳ��ſ����Ķ�������˵������λ" + RANK_D->query_respect(ob)
                                + "������Ķ���ѽ��:)\n" NOR);
                        tell_room( environment(), "ө������ĳ��ſ��"
				+ ob->name() + "����С����˵��Щ����\n", ({ ob, ob }) );
                        break;
                case 2:
                        tell_object( ob, GRN "ө������ĳ��ſ����Ķ�������˵������λ" + RANK_D->query_respect(ob)
                                + "���������׽�Բأ��ò��ã�\n" NOR);
                        tell_room( environment(), "ө������ĳ��ſ��"
                                + ob->name() + "����С����˵��Щ����\n", ({ ob, ob }) );
                        break;
		case 3:
			tell_object( ob, GRN "ө������ĳ��ſ����Ķ�������˵�����������ม�:)\n" NOR);
			tell_room( environment(), "ө������ĳ��ſ��" + ob->name() + "����С����˵��Щ����\n", ({ ob, ob }) );
			break;
		case 4:
			tell_object( ob, GRN "ө������ĳ��ſ����Ķ�������˵������ҵд������:)\n" NOR);
			tell_room( environment(), "ө������ĳ��ſ��" + ob->name() + "����С����˵��Щ����\n", ({ ob, ob }) );
        }
}

