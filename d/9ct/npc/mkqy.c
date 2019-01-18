// ������� "��ԯ��� Ħ����Ҷ" by Calvin

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
       set_name(HIR"Ħ����Ҷ"NOR, ({"moke qieye","moke","qieye","ye","mo","mokeqieye","mkqy","tianshen"}));
        set("title", HIR"��ԯ���"NOR);
        set("long", "������������,��Ů�����תΪ�������������\n");
       set("gender", "����");
       set("age", 100);
        set("per", 25);
        set("str", 50);
        set("int", 25);
        set("con", 25);
        set("spi", 25);

        set("attitude", "heroism");

        set("combat_exp", 15000000);
          set("daoxing", 10000000);
        set("eff_dx", -500000);
        set("nkgain", 500);

        set("class","yaomo");
        set("max_kee", 10000);
        set("max_sen", 10000);
        set("force", 10000);
        set("max_force", 6000);
        set("force_factor", 300);
        set("max_mana", 6000);
        set("mana", 8000);
        set("mana_factor", 300);
       
        set_skill("unarmed", 350);
        set_skill("dali-bang", 350);
        set_skill("dodge", 350);
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("spear", 380);
        set_skill("fork", 350);
        set_skill("stick", 350);
        set_skill("spells", 350);
        set_skill("huoyun-qiang", 350);
        set_skill("moshenbu", 350);
        set_skill("moyun-shou", 350);
         set_skill("huomoforce", 380);
        set_skill("pingtian-dafa", 350);
        map_skill("force", "huomoforce");
        map_skill("spells", "pingtian-dafa");
        map_skill("unarmed", "moyun-shou");
        map_skill("stick", "dali-bang");
        map_skill("dodge", "moshenbu");
        map_skill("parry", "dali-bang");
        map_skill("spear", "huoyun-qiang");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "stick","qzld" :),
                (: cast_spell, "sanmei" :),
        }));


        create_family("���ƶ�", 1, "��");
        setup();
        carry_object("/d/9ct/zb/stick")->wield();
        carry_object("/d/wizz/cigar/zb/shield")->wear();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name") == "���ƶ�") {

                if( (int)ob->query("max_mana") > 500 
                && (int)ob->query("max_force") > 500
//                && !(int)ob->query("kusong") ) {
                ) {
        
                command("nod");
                command("recruit " + ob->query("id"));
                return ;
                }
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
                ob->set("title", HIR"���ƶ�����ʥʹ"NOR);
                ob->set("kusong/Teach_Hong", 1);
        }
}

