// jianxin.c
// ��������  ���Ͻ���ָ����
// ��ն�ε�  δ���������ʹ��

#include <ansi.h>

inherit NPC;


int choose_book();
void get_book(string arg, object ob);

void create()
{
	set_name( HIW "糴彣��" NOR , ({ "feicun jianxin" , "feicun" , "jianxin" }));
	set("gender", "����");
	set("title", HIR"�˿�"NOR);
	set("age", 25);
	set("long", "����һλӢ�����ݵĽ��͡�����������ʮ�Ĵ��̳��ˡ��ºš������ְε�ի����
	             �����߳���ɱ�˲�գ�ۣ���ʹ�����ŷ�ɥ����\n");
	set("shen_type", 1);
	set("per", 40);
	set("attitude", "peaceful");
	set("max_kee", 10000);
	set("max_sen", 10000);
	set("max_gin", 5000);
	set("force", 50000);
	set("max_force", 50000);
 	set("force_factor", 500);
 	set("max_mana", 50000);
 	set("mana", 50000);
 	set("mana_factor", 500);
 	set("combat_exp", 900000000);
	set("daoxing", 50000000);
	set_skill("unarmed", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("force", 400);
	set_skill("sword", 350);
	set_skill("feitian-jian", 350);
	map_skill("sword", "feitian-jian");
	map_skill("parry", "feitian-jian");
	map_skill("dodge", "feitian-jian");


	set("inquiry", ([
            "����������" : "��ѧ�ղ�������ֻ���߳ɵĹ�����������ϣ��������ҿ�Ҫ����ʦ���ˡ�\n",
            "�ȹ���ʮ��" : "�����ҵ�ʦ����������������? ��ͨ���������˵ġ�\n",
            "ʦ��" : "�ҵ�ʦ���Ǳȹ���ʮ�ɣ�˵�����������ҵĽ����ɱ�������ˡ�\n",
            "����" : (: choose_book :),
	]) );


	setup();

	carry_object("/d/dongying/obj/jxcloth")->wear();
        if (clonep(this_object())) { 
        object ob;
        if (ob = carry_object(BINGQI_D("sword") + "/niren-sword")) ob->wield(); } 
}


int choose_book()
{
        if( !this_player()->query_temp("pass_jianxin") ) {
        object me = this_player();
        write(HIG"\n��Ҫ�ı��飺\n\n"NOR);
        write(HIW"(1)"HIC" ����ƪ "HIW"(2)"HIM" ����ƪ "HIW"(3)"HIY" �ռ�ƪ \n\n"NOR);
        write(HIG"��ѡ��(ȡ���밴 q �� Q)"NOR);
        input_to( (: get_book :), me);
        return 1;
        } else {
        return 0;
        }
}

void get_book(string arg, object ob)
{
	int  order;
        string order2;
        object shu;
   
        if( arg == "q" || arg == "Q" )    return;
        sscanf(arg, "%d", order);

        if (order <= 0 || order > 3)
        {   
        write(HIG"\n\n��Ҫ�ı��飺\n\n"NOR);
        write(HIW"(1)"HIC" ����ƪ "HIW"(2)"HIM" ����ƪ "HIW"(3)"HIY" �ռ�ƪ \n\n"NOR);
        write(HIG"��ѡ��(ȡ���밴 q �� Q)"NOR);
        input_to( (: get_book :), ob);
        return;
        }

        switch(order) {
        case 1:
		shu=new("/d/dongying/obj/feitian-book1");
		shu->set("value", 0);
		message_vision("\n\n�������ִӻ����ó�һ"+ shu->query("unit")+shu->query("name")+" ���˸�$N \n", ob);
		shu->move(ob);
	break;

        case 2:
		shu=new("/d/dongying/obj/feitian-book2");
		shu->set("value", 0);
		message_vision("\n\n�������ִӻ����ó�һ"+ shu->query("unit")+shu->query("name")+" ���˸�$N \n", ob);
		shu->move(ob);
	break;

        case 3:
		shu=new("/d/dongying/obj/feitian-book3");
		shu->set("value", 0);
		message_vision("\n\n�������ִӻ����ó�һ"+ shu->query("unit")+shu->query("name")+" ���˸�$N \n", ob);
		shu->move(ob);
	break;
                      }
        return;
}

