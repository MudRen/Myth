//Cracked by Roath
 
inherit NPC;
string ask_hanshan();

void create()
{
        set_name("��������", ({"faming zhanglao","monk", "faming","zhanglao"}));
        set("long",
                "���������ǻ����µ����֣���ɫׯ�أ���ֹ������һ�����ǡ�
��˵����һ�����գ�Ҳ�ܺ��绽�꣬ȴ������������ĺ��С�\n");
   set("title", "����");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 55);
        set("per", 23);
        set("max_kee", 900);
        set("max_sen", 600);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 40);
        set("max_mana", 500);
        set("mana", 900);
        set("mana_factor", 30);
        set("combat_exp", 200000);
	set("daoxing",200000);	
        set("shen_type", 1);

        set("eff_dx", 90000);
        set("nkgain", 300);


        set_skill("force", 90);
        set_skill("unarmed", 90);
        set_skill("dodge", 90);
        set_skill("jienan-zhi", 90);
        set_skill("parry", 90);
        set_skill("spells", 90);
        set_skill("buddhism", 90);
        map_skill("unarmed", "jienan-zhi");
        map_skill("spells", "buddhism");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
        }) );
        set("inquiry", ([
                "Ѫ��": (: ask_hanshan :),
                "����": (: ask_hanshan :),
                ]));
        set("count",1);
        setup();
        carry_object("/d/obj/cloth/monkcloth")->wear();
        carry_object("/d/quest/longzhu/obj/jingshi1"); 
}

string ask_hanshan()
{
        object ob=this_player();
        object me=this_object();
        object xueshu,hanshan;
       

        if (query("count") < 1)
                return "�����Ѿ�û���ˡ�";
//�ж��Ƿ�dntg over by dragon
        if( ob->query("obstacle/jz") == "done" )
        {
        command("shake");
        return("ƶɮ��֪��");
        }
       
        if( present("xue shu", ob) || present("han shan", ob) )
        return("�㲻������");

        xueshu = new("/d/jz/obj/xueshu");
        hanshan = new("/d/jz/obj/hanshan");
        switch ( random(2) ) {
        case 0:
        xueshu->move(ob);
        break;
        case 1:
        hanshan->move(ob);
        break;
        }  
      add("count",-1);
      return("���ǵ�����������Ϸ��ֵģ�����ȥ�ɡ�");
}        
        
        
