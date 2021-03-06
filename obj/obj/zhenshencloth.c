#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
    seteuid(0);
    set_name(HIW"圣灵"HIY"法衣" NOR,({"shengling fayi", "shengling cloth"}));
    set_weight(8000);
    if(clonep())
        set_default_object(__FILE__);
    else {
        set("unit","件");
        set("value", 1);
        set("no_get", 1);
        set("no_give", 1);
        set("no_sell", 1);
        set("no_drop", 1);
        set("no_put", 1);
        set("material","cloth");
        set("armor_prop/armor", 10);
        set("long","\n此物乃是我佛如来凡胎超度金身之时，包裹真身的金丝布所织成的法衣。\n");
        }
        setup();
}

void reset()
{
    if( !environment() ||  //mon 2/4/98
        query("owner_id") != getuid(environment()) )  {
        tell_object(this_player(),"只见"+this_object()->query("name")
        +"凌空而去，霎时间不见了踪影。\n");  
        destruct(this_object());
        return;
    }
}



string ob_hit_msg(object me, object victim,int damage_bonus)
{
    object fabao=this_object();
    string msg;
    int succ=random(3);
    if( succ ) {
    msg=fabao->name()+NOR+BLINK+HIY+"爆发出金黄色耀眼光芒护住$n全身...\n"NOR;
    me->set_temp("saiya_baohu",1);
    return COLOR_D->random_jjww()+msg;
        }
        else return "";
}

int ob_hit_int(object me, object victim,int damage_bonus)
{
        int level,damage;
        object ob=this_object();
        level=(int)ob->query("level");
        if( me->query_temp("zhenshen_baohu") )
        {
        damage= damage_bonus*(level/50);
        if( damage<damage_bonus/10 ) damage=damage_bonus/10;
        if( damage>damage_bonus/3 ) damage=damage_bonus/3;
        damage=random(damage/2)+damage/2;
        me->delete_temp("zhenshen_baohu");
        return -damage;
        }
        else return 0;
}
