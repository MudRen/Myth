#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
    seteuid(0);
    set_name(HIY"����"HIW"ս��" NOR,({"saiya zhanyi", "saiya cloth"}));
    set_weight(5000);
    if(clonep())
        set_default_object(__FILE__);
    else {
        set("unit","��");
        set("value", 1);
        set("no_get", 1);
        set("no_give", 1);
        set("no_sell", 1);
        set("no_drop", 1);
        set("no_put", 1);
        set("material","cloth");
        set("armor_prop/armor", 10);
        set("long","һ�����������˵�ս�¡�\n");
        }
        setup();
}

void reset()
{
    if( !environment() ||  //mon 2/4/98
        query("owner_id") != getuid(environment()) )  {
        tell_object(this_player(),"ֻ��"+this_object()->query("name")
        +"��ն�ȥ����ʱ�䲻������Ӱ��\n");  
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
    msg=fabao->name()+NOR+BLINK+HIY+"���������ɫҫ�۹�â��ס$nȫ��...\n"NOR;
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
        if( me->query_temp("saiya_baohu") )
        {
        damage= damage_bonus*(level/50);
        if( damage<damage_bonus/10 ) damage=damage_bonus/10;
        if( damage>damage_bonus/3 ) damage=damage_bonus/3;
        damage=random(damage/2)+damage/2;
        me->delete_temp("saiya_baohu");
        return -damage;
        }
        else return 0;
}
