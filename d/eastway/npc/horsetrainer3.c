// horsetrainer2.c writted by jie 2001-2-5
// ����ѵ��֮���������������ѧ������
// ����gold
// u/jie/horsetrainer3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("С���", ({ "bimawen xiao", "xiao"}) );
        set("gender", "Ů��" );
        set("title",HIY"��������"NOR);
        set("age", 18);
        set("long","һ���������Ե�С����������������˺��(train)�����������ս������\n���������ʥҲ�ι��˼�ְ������������һְһֱ������»ٺ��ʮ�ַ��\n");
        set("combat_exp", 5000);
        set("daoxing", 1000);
        set("attitude", "friendly");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
        carry_object("/d/qujing/tianzhu/obj/guanpao")->wear();

}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "train");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "С���˵������λ" + RANK_D->query_respect(ob)
                                + "���������ҶԴ�train�����㸶���ӣ�\n");
                        break;
                case 1:
                        say( "С���Ц������λ" + RANK_D->query_respect(ob)
                                + "�����ģ��˲������ģ�\n");

                        break;
        }
}

int do_train(string arg)
{
        object ob;
        object pet_ob;
        string pet_id;
        object gold;
        int cost;
        string which;
        ob = this_player();
        if(ob->is_busy())
        return notify_fail("����æ���ء�\n");
        if (!ob->query("pet/pet_id"))
        return notify_fail("С��ٵ������㲢û���������ʲô���֣���\n");
        pet_id=ob->query("pet/pet_id");
        if( !objectp(pet_ob=present(pet_id, ob)) && 
                !objectp(pet_ob=present(pet_id, environment(ob))))
        return notify_fail("С��ٵ������������û����һ�����𣿣�\n");
        if(pet_ob->query("owner") != ob->query("id")) 
        return notify_fail("С��ٵ������Ǻ�������İɣ���\n");
        switch (random(2)){
        case 0: which = "combat_exp"; break;
        case 1: which = "daoxing"; break;
        }
//�ã��������ڻ�Ǯ�����������wx, dh
        cost = to_int(sqrt(to_float(((int)pet_ob->query("combat_exp")+(int)pet_ob->query("combat_exp")+100))))/5;
        gold = present("gold_money", ob);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("������û��"+chinese_number(cost)+"�����ӡ�\n");
        pet_ob->add(which,cost*50);
        pet_ob->save();
        gold->add_amount(-cost);
        command("say ���ˣ��´��ٴ�\n");
        return 1;
}

