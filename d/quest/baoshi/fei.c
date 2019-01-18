// fei.c
// rewritten by mudring

#include <ansi.h>

inherit JOBNPC;

void _leave();
void leave();
void set_skills();

int announced=0;

void create()
{
    seteuid(getuid());
    set_name("��������",({"zei"}));
    set("age",30);
    set("str",30);
    set("per",20);
    set("combat_exp",5000);
    set("attitude", "heroism");
    set_skill("unarmed",200);
    set("force_factor",100);
    set("force",2000);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :)
    }));

    setup();
    carry_object("/d/obj/drug/jinchuang");
    carry_object("/d/obj/drug/jinchuang");
    carry_object("/d/obj/drug/jinchuang");
    carry_object("/d/obj/drug/jinchuang");
    carry_object("/d/obj/drug/jinchuang");
    carry_object("/d/obj/drug/jinchuang");
    add_money("gold", 1+random(3));
}

void init()
{
    object me=this_object();
    object who=this_player();
    int type;
    int t=query("stay_time");

    ::init();
    
    if(t && time()>(t+300)) {
        remove_call_out("leave");
        call_out("leave",1);
        return;
    }

    if(t && time()>t) {
        remove_call_out("_leave");
        call_out("_leave",300);
    }
}

void copy_status(object me)
{
        object *inv;
        mapping skill_status,map_status;
        string *sname,*mname;
        int i, eff_dx, nk_factor;
        set_name("����",({"fei zei","zei"}));
        set("title",query("target")+"��������");
        set("enable_type","����");
        set("str",100);
        set("int",30);
        set("con",30);
        set("per",30);
        set("cor",100);
        set("spi",100);
        set("cps",100);
        set("kar",30);

        set("max_kee",4000+random(1000));
        set("eff_kee",4000+random(1000));
        set("kee",4000+random(1000));

        set("max_gin",3000+random(1000));
        set("eff_gin",3000+random(1000));
        set("gin",3000+random(1000));

        set("max_sen",3000+random(1000));
        set("eff_sen",3000+random(1000));
        set("sen",3500+random(1000));

        set("max_force",3000+random(1000));
        set("force",6000+random(1000));
        set("force_factor",300);

        set("max_mana",3000+random(2000));
        set("mana",6000+random(2000));
        set("mana_factor",350);
        set("combat_exp",1500000+random(1000000));
        set("daoxing",800000+random(1000000));

        set("stay_time",time()+600+random(60));
        set("nk_gain", 100+random(50));
        set("nk_factor", 12);

        
        set("bellicosity",300);
        carry_object("/d/qujing/jindou/obj/boots")->wear();
        carry_object("/d/qujing/jindou/obj/finger")->wear();
        carry_object("/d/qujing/jindou/obj/hands")->wear();
        carry_object("/d/qujing/jindou/obj/head")->wear();
        
        set_skills();

        carry_object("/d/obj/drug/jinchuang");       
        reset_eval_cost();
}

void die()
{

    int reward;
    object ob,me;
    ob = query_temp("last_damage_from");
    me=this_object();
    if (!ob)
    {
        leave();
        return; 
    }
    CHANNEL_D->do_channel( this_object(), "rumor",
               sprintf("����%s��"NOR+YEL"<%s>"HIM"��%sɱ���ˡ�"NOR,
                       query("target"),query("name"), ob->name() ));
    reward = query("nk_gain") * query("nk_factor");
    ob->add("kill/nkgain",reward);
    ob->add("daoxing",reward);
    ob->add("potential", reward*2/3);
    tell_object(ob,"\n��õ���"+COMBAT_D->chinese_daoxing(reward)+"���к�"
                + reward/2 + "��Ǳ�ܣ�\n" );
    MONITOR_D->report_system_object_msg(ob,
              "�õ���"+COMBAT_D->chinese_daoxing(reward)+"���к�"
              + reward/2 + "��Ǳ�ܣ�");
    ::die();
    destruct(this_object());                                                                  
}

void unconcious()
{
    if (query("kee")<0 || query("sen")<0) die(); 
    else ::unconcious();
}

void heart_beat()
{
    if (query("eff_kee") < query("max_kee"))
    {
        command("eat yao");
    }

    ::heart_beat();
}

void _leave()
{
        object me=this_object();
        if(me->is_fighting() || me->is_busy())
        return;
        leave();
}

void leave()
{
    if (this_object())
    {
        if(environment())
        {
            command("say �ٺ٣�������ô���ˣ������Ƿ�ƽ�˾��ˡ�����");
            message("vision",HIB + name() + 
                  "����һ�Σ����һ������ɢȥ�ˡ�\n" NOR,environment());
        }
        destruct(this_object());
    }

    return;
}

int attack()
{
    object opponent;
    clean_up_enemy();
    opponent = select_opponent();
    if (objectp(opponent))
    {
        if (opponent->query("family/family_name")==this_object()->query("target")
            && userp(opponent)
            && !living(opponent)
            && environment()==environment(opponent))
        {
            call_out("leave",1);
            return 0;
        }

        set_temp("last_opponent", opponent);
        COMBAT_D->fight(this_object(), opponent);
        return 1;
    } else
        return 0;
}

