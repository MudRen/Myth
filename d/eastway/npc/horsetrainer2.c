// horsetrainer2.c writted by jie 2001-2-5
// ����ѵ��֮����������������Գ���int,kar����Ľ�
// ����gold
// u/jie/horsetrainer2
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "bimawen hu", "hu"}) );
        set("gender", "Ů��" );
        set("title",HIY"��������"NOR);
        set("age", 44);
        set("long","һ���������Եĺ�����������(train)����������Զ��б仯��\n���������ʥҲ�ι��˼�ְ������������һְһֱ������»ٺ��ʮ�ַ��\n");
        set("combat_exp", 50000);
        set("daoxing", 60000);
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
                        say( "����˵������λ" + RANK_D->query_respect(ob)
                                + "���ϸ�����˳�Ů���֣���������\n");
                        break;
                case 1:
                        say( "����Ц�������Ǻ������£�����ٺ»���٣�ȫ�����ʥ�ĸ���\n");

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
        return notify_fail("���ٵ������㲢û���������ʲô���֣���\n");
        pet_id=ob->query("pet/pet_id");
        if( !objectp(pet_ob=present(pet_id, ob)) && 
                !objectp(pet_ob=present(pet_id, environment(ob))))
        return notify_fail("���ٵ������������û����һ�����𣿣�\n");
        if(pet_ob->query("owner") != ob->query("id")) 
        return notify_fail("���ٵ������Ǻ�������İɣ���\n");
        switch (random(6)){
        case 0: which = "str"; break;
        case 1: which = "cor"; break;
        case 2: which = "per"; break;
        case 3: which = "spi"; break;
        case 4: which = "cps"; break;
        case 5: which = "con"; break;
                }       
//�ã��������ڻ�Ǯ�������������������֮һ
        cost = (int) pet_ob->query(which) ;
        cost *= cost;
        gold = present("gold_money", ob);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("������û��"+chinese_number(cost)+"�����ӡ�\n");
        pet_ob->add(which,1);
        pet_ob->save();
        gold->add_amount(-cost);
        command("say ���������´��ϸ��ٰ����࣡\n");
        return 1;
}

