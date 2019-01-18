#include <armor.h>
#include <ansi.h>
//inherit EQUIP;
inherit F_SAVE;
inherit F_BACKUP;
inherit CLOTH;

void create()
{
    seteuid(0);
    set_name(HIY"������" NOR,({"jia sha", "jiasha"}));
    set_weight(10000);
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
        set("long","һ�������״͵����ġ�\n");
        }
        setup();
}

void reset()
{
    if( !environment() ||  //mon 2/4/98
        query("owner_id") != getuid(environment()) )  {
        destruct(this_object());
        return;
    }
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
   string id, series;

   id = query("owner_id");
   if( !id ) return 0;

   return sprintf(DATA_DIR "jiasha/%c/%s", id[0], id);
}

int save()
{
   return ::save();
}

void setup()
{
   ::setup();
}

int query_unique()  { return 1; }

string ob_hit_msg(object me, object victim,int damage_bonus)
{
    object fabao=this_object();
    string msg;
    int succ=random(3);
    if( succ ) {
    msg=fabao->name()+NOR+WHT+"���������⻤ס$nȫ��...\n"NOR;
    me->set_temp("jiasha_baohu",1);
    return COLOR_D->random_jjww()+msg;
        }
        else return "";
}

int ob_hit_int(object me, object victim,int damage_bonus)
{
        int level,damage;
        object ob=this_object();
        level=(int)ob->query("level");
        if( me->query_temp("jiasha_baohu") )
        {
        damage= damage_bonus*(level/50);
        if( damage<damage_bonus/10 ) damage=damage_bonus/10;
        if( damage>damage_bonus/3 ) damage=damage_bonus/3;
        damage=random(damage/2)+damage/2;
        me->delete_temp("jiasha_baohu");
        return -damage;
        }
        else return 0;
}

