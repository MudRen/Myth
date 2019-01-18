//inherit NPC;

#include <ansi.h>

inherit F_VENDOR_SALE;

void create()
{
         set_name("��ѩ��", ({"bing xue er"}));
        set("title",HIR"��ȿɰ� Ư���ٷ�"NOR);
          set ("color", HIW);
        set("gender", "Ů��");
        set("age", 20);
        set("long", HIM"\n��ѩ���Ǳ�ѩ���ɳ�ר�ŷ���װ������Ů�������쳣��\n"NOR);

        set("combat_exp", 70000);
        set_skill("fonxansword", 30);
        set_skill("sword", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("moondance", 50);
        map_skill("dodge", "moondance");
        map_skill("sword", "fonxansword");
        map_skill("parry", "fonxansword");
        set("force", 200);
        set("max_force", 200);
        set("per", 40);
        set("force_factor", 5);

        set("vendor_goods", ([
            "ming jing" : "/d/wizz/cigar/zb/jing",
            "dun armor" : "/d/wizz/cigar/zb/tianjia",
            "zibing kui" : "/d/wizz/cigar/zb/kui",
            "biluo pao" : "/d/wizz/cigar/zb/pao",
            "feitian shoes" : "/d/wizz/cigar/zb/xue",
            "tian dun" : "/d/wizz/cigar/zb/shield",
            "tiancai pifeng" : "/d/wizz/cigar/zb/pifeng",
            "yinyang ring" : "/d/wizz/cigar/zb/jiezhi",
            "qilin wan" : "/d/wizz/cigar/zb/wan",
            "xiang lian" : "/d/wizz/cigar/zb/necklace",
        ]) );

        setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();
        carry_object("/obj/loginload/shoes.c")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",1, ob);
        }
        add_action("do_vendor_list", "list");
        add_action("do_bid", "bid");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( name()+"���͹�����Щʲô�������ﶼ���������е�װ����\n");
                        break;
        }
}
int accept_fight(object me)
{
        command("say СŮ���ҿɲ�����ϰ�䣬��ջ��¥�в������֣������ȥ���ԣ�\n");
        return 1;
}
int do_bid(string arg)                                                       
{
        object who = this_player();                                           
        object me = this_object();                                            
        if(!arg || present(arg,environment(me))!=me) return 0;                
           command("joke "+who->query("id"));
                return 1;
}
