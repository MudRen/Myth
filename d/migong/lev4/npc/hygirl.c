//�Թ��е�seller

#include <ansi.h>


inherit F_VENDOR_SALE;

void greeting(object ob);
int do_kiss(string arg);

void create()
{
        set_name(HIY"�����콾"NOR, ({"yuwen tianjiao", "tianjiao", "girl"}));
        set("title", HIW"�������㣬�����߻�"NOR);
        set("gender", "Ů��");
        set("family/family_name", "�¹�");
        set("age", 16);
        set("long",
        HIG "�����������ǵ���Ů��ʮ�ֹ��ɣ�����ϲ����\n"
        NOR);
        set("str", 50);
        set("int", 90);
        set("con", 80);
        set("dex", 80);
        set("per", 50);
        set("kee", 50000);
        set("max_kee", 50000);
        set("sen", 30000);
        set("max_sen", 30000);
        set("man", 90000);
        set("max_mana", 90000);
        set("force", 90000);
        set("max_force", 90000);
        set("force_factor", 300);
        set("combat_exp", 100000000);
        set("daoxing", 100000000);
        set_skill("force", 500);
        set_skill("spells",500);
        set_skill("moonforce", 500);
        set_skill("moonshentong", 500);
        set_skill("blade", 500);
        set_skill("aohan-liujue", 500);
        set_skill("unarmed", 400);
        set_skill("baihua-zhang", 400);
        set_skill("dodge", 400);
        set_skill("moondance", 400);
        set_skill("parry", 400);
        set_skill("sword", 400);
        set_skill("snowsword",400);
        set_skill("daya-jian", 400);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
           (: perform_action, "sword", "tian" :),
           (: perform_action, "sword", "hanyue" :),
           (: perform_action, "blade", "bingyu" :),
           (: command("unwield sword") :),
           (: command("wield sword") :),
           (: command("unwield blade") :),
           (: command("wield blade") :),
           (: cast_spell, "arrow" :),  
           (: cast_spell, "mihun" :),
           (: cast_spell, "shiyue" :),             
        }) );
        map_skill("force"  , "moonforce");
        map_skill("spells"  , "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("dodge"  , "moondance");
        map_skill("sword"  , "snowsword") ;
        map_skill("blade"  , "aohan-liujue");
        map_skill("parry"  , "aohan-liujue");

        set("inquiry", ([       
                       "��������" : "�������ҵ����ˣ��й����˵��¿������ҡ� ",
                       "����" : "���˴�Ż���˯����������������post��",
        ]) );  
        set("vendor_goods", ([
            "lei lingzhu" : "/d/obj/baowu/leizhu.c",
            "jiudai" : "/d/moon/obj/jiudai",
            "pillow" : "/d/obj/misc/pillow",
            "fire" : "/obj/fire",
            "ball" : "/d/obj/misc/crystalball",
            "ring" : "/d/9ct/zb/jiezhi",
            "whip" : "/d/9ct/zb/zhaoxia",
            "sword" : "/d/9ct/zb/sword",
            "blade" : "/d/9ct/zb/blade",
            "staff" : "/d/9ct/zb/pudu",
            "kui" : "/d/9ct/zb/kui",
            "armor" : "/d/9ct/zb/tianjia",
            "shield" : "/d/9ct/zb/shield",
            "jing" : "/d/9ct/zb/jing",
            "axe" : "/d/9ct/zb/axe",
            "fork" : "/d/9ct/zb/fork",
            "necklace" : "/d/9ct/zb/necklace",
            "pao" : "/d/9ct/zb/pao",
            "pifeng" : "/d/9ct/zb/pifeng",
            "stick" : "/d/9ct/zb/stick",
            "wan" : "/d/9ct/zb/wan",
            "shoes" : "/d/9ct/zb/xue",
            "zhua" : "/d/9ct/zb/zhua",
            "spear" : "/d/obj/weapon/spear/huaji2",
            "yao" : "/d/obj/drug/jinchuang",
            "dan" : "/d/obj/drug/hunyuandan", 
            "yanlei" : "/d/obj/drug/yanlei", 
            "wan" : "/d/wizz/junhyun/obj/wan", 
            "guo" : "/d/pansi/obj/guo",
            "he" : "/d/calvin/obj/he",   
            "chan" : "/d/obj/drug/chan",   
        ]) );

        setup();
        carry_object("/d/zhuxian/obj/wuchen");
        carry_object("/d/gumu/obj/zixue-blade")->wield();
        carry_object("/d/gumu/obj/yuyi")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
        return;
        if ((string)ob->query("id") == "wuyou")
        {
                command("jump wuyou");
                message_vision(HIM "\n�����콾���˵�˵�������������������� \n"NOR, ob);
        }
        else
        {
                command("wanfu "+(string)ob->query("id"));
                message_vision(HIY"\n�����콾�����˵������"+RANK_D->query_respect(ob)+"��ӭ���ٱ��ꡣ�� \n"NOR, ob);
        }
}

void attempt_apprentice(object ob)
{
        command("say ���ʦ������ȥ�����������ǰɣ�");
}

