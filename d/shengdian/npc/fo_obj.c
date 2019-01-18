#include <ansi.h>
inherit NPC;
inherit F_SAVE;

void create()
{
        set_name("��", ({ "fo", "zun fo" }) );
        set("gender", "Ů��" );
        set("age", 30);
        set("str", 30);
        set("per", 30);
        set("int", 30);
        set("long", "�������" );
        set("attitude", "heroism");
        set("combat_exp", 100000);
        set("daoxing", 100000);
        set("current_player","none of us");

        setup();

       carry_object("/d/nanhai/obj/jiasha")->wear();


}

void init()
{
        object me = this_object();



        if (!me->query("fo_id"))
                me->reset_me(me);
       if (! me->restore())
        me->fully_recover(me);


        me->setup();
}

void reset_me (object me)
{

        me->set_name("��", ({ "fo", "zun fo" }) );
        me->set("gender", "Ů��" );

        me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");
        me->set("attitude", "heroism");
        me->set("current_player","none of us");

        me->set("str", 30);
        me->set("per", 30);
        me->set("int", 30);
        me->set("age", 30);

        me->set("weapon", 0);
        me->set("armor", 0);

        me->set_skill("force",  60);
        me->set_skill("spells", 60);
        me->set_skill("unarmed",60);
        me->set_skill("sword",  60);
        me->set_skill("dodge",  60);
        me->set_skill("parry",  60);

        me->set("max_gin", 600);
        me->set("eff_gin", 600);
        me->set("gin", 600);
        me->set("max_kee", 600);
        me->set("eff_kee", 600);
        me->set("kee", 600);
        me->set("max_sen", 600);
        me->set("eff_sen", 600);
        me->set("sen", 600);
        me->set("force", 600);
        me->set("max_force", 600);
        me->set("mana", 600);
        me->set("max_mana", 600);
        me->set("force_factor", 20);
        me->set("combat_exp", 100000);
        me->set("daoxing", 100000);

        me->setup();
        reset_eval_cost();

}

int fully_recover (object me)
{
        object *inv;
        object ob;
        string player_name;
        object current_player;

        reset_eval_cost();

        me->set("eff_gin", me->query("max_gin"));
        me->set("gin",     me->query("max_gin"));
        me->set("eff_kee", me->query("max_kee"));
        me->set("kee",     me->query("max_kee"));
        me->set("eff_sen", me->query("max_sen"));
        me->set("sen",     me->query("max_sen"));
        me->set("force",   me->query("max_force"));
        me->set("mana",    me->query("max_mana"));




        reset_eval_cost();
        return 1;
}


int record(string id,object ob)
{
        object *inv,me;
        mapping hp_status, skill_status, map_status;
        string *skillnames, *mapnames;
        int i, weapon_cnt, armor_cnt;

        reset_eval_cost();
        me=this_object();
        hp_status = ob->query_entire_dbase();

        me->set("str", hp_status["str"]);
        me->set("per", hp_status["per"]);
        me->set("int", hp_status["int"]);
        me->set("age", hp_status["age"]);
        me->set_name(ob->query("name")+"��", ({ob->query("id")+" foshen" ,}) );

        me->set("max_gin",     hp_status["max_gin"]);
        me->set("eff_gin",     hp_status["eff_gin"]);
        me->set("gin",         hp_status["gin"]);
        me->set("max_kee",     hp_status["max_kee"]);
        me->set("eff_kee",     hp_status["eff_kee"]);
        me->set("kee",         hp_status["kee"]);
        me->set("max_sen",     hp_status["max_sen"]);
        me->set("eff_sen",     hp_status["eff_sen"]);
        me->set("sen",         hp_status["sen"]);
        me->set("max_force",   hp_status["max_force"]);
        me->set("force",       hp_status["force"]);
        me->set("max_mana",    hp_status["max_mana"]);
        me->set("mana",        hp_status["mana"]);
        me->set("gender",      hp_status["gender"]);
        me->set("combat_exp",  hp_status["combat_exp"]);
        me->set("daoxing",     hp_status["daoxing"]);

        me->set("eff_gin", me->query("max_gin"));
        me->set("gin",     me->query("max_gin"));
        me->set("eff_kee", me->query("max_kee"));
        me->set("kee",     me->query("max_kee"));
        me->set("eff_sen", me->query("max_sen"));
        me->set("sen",     me->query("max_sen"));
        me->set("force",   me->query("max_force"));
        me->set("mana",    me->query("max_mana"));
        me->set("long",   "���÷���\n"+ob->query("long"));
        me->set("fo_id",id);
        skill_status = me->query_skills();
        if ( mapp(skill_status) )
        {
                skillnames  = keys(skill_status);

                for(i=0; i<sizeof(skillnames); i++)
                {
                        me->delete_skill(skillnames[i]);
                }
        }

        skill_status = ob->query_skills();
        if ( mapp(skill_status) )
        {
                skillnames  = keys(skill_status);

                for(i=0; i<sizeof(skillnames); i++)
                {
                        me->set_skill(skillnames[i], 350);
                }
        }

        me->set("force_factor",me->query_skill("force")*3/4);

        reset_eval_cost();

        if ( mapp(map_status = me->query_skill_map()) )
        {
                mapnames = keys(map_status);

                for(i=0; i<sizeof(mapnames); i++)
                {
                        me->map_skill(mapnames[i]);
                }
        }

        map_status = ob->query_skill_map();
        if ( mapp(map_status) )
        {
                mapnames  = keys(map_status);

                for(i=0; i<sizeof(mapnames); i++)
                {
                        me->map_skill(mapnames[i], map_status[mapnames[i]]);
                }
        }

        me->setup();
        me->save();



        return 1;
}


string query_save_file()
{
        string str = query("save_file");

        if (str)
                return str;
         else return DATA_DIR+"/shengdian/fo_obj";

}

void set_save_file(string str)
{
        set("save_file",str);
}

int recognize_apprentice(object ob)
{

        if(this_player()->query("id")!=this_object()->query("fo_id"))
        return notify_fail("�����������������֮Ե��\n");

    return 1;
}


