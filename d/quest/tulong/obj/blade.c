#include <weapon.h>
#include <ansi.h> 
inherit BLADE;

void create()
{
        set_name(HIY"���鵶"NOR, ({ "spirit blade", "blade" })); 
        set("long", "����ı��ӵ�о����������\n");
        set("no_get",1);
        set("no_give",1);
        set("no_steal",1);
        set("no_sell",1);
        set("no_put",1);
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "iron");
                set("wield_msg", HIC"$N"+HIC"���ֽ�ӡ����ĿĬ�����һ���â��$N"+HIC"����������$n"NOR+HIC"�������Ρ�\n"NOR);
                set("unwield_msg", "$n"+HIC"��$N"+HIC"����һԾ���𣬻�Ϊһ����硣\n"NOR); 
                   set("skill", ([
                "name": "spirit-blade",    // name of the skill
                "exp_required": 1000,    // minimum combat experience required
                "sen_cost":    2,    // jing cost every time study this
                "difficulty":   10,    // the base int to learn this skill
                "max_skill":   160,    // the maximum level you can learn to
            ]) );
        }
        init_blade(120);
        setup();
}

void owner_is_killed()
{
        write(HIY"ֻ��һ����紵���������ǡ���\n"NOR);
       destruct(this_object());
}
/*
int query_autoload()
{
        write(HIG"һ����������࣬�·������ʲô���\n"NOR);
       return 1;
}
*/
void init()
{
    add_action("do_back","back"); 
    add_action("do_nopoison","nopoison"); 
    add_action("do_change","change");    
    add_action("do_summons","summons");
}
 
int do_back(string arg)
{
    string name;
    name = (string)this_player()->query("name"); 
    if( (int)this_player()->query("sen") < 200 )
                return notify_fail("��ľ����޷����У�\n");
    if( !arg ) return notify_fail("��Ҫ������? \n");
    {
        if ( arg == "spirit" )
        {
            message_vision(HIG"$NĬ���������"NOR+HIY"���鵶"NOR+HIG"��Ϊһ����磬�������衣\n"NOR,this_player() );
            this_player()->receive_damage("sen",50);
            tell_room(environment(this_player()),
                 name+"����Ӱ��ʧ������С�\n",this_player() );
            tell_room("/d/city/kezhan",
                 name+"����Ӱ������һ������С�\n",this_player() );
            this_player()->move("/d/city/kezhan");
         }
     }
     return 1;
}
 
int do_nopoison(string arg)
{     
        object me;
        me = this_player(); 
        if( (int)me->query("sen") < 200 )
                return notify_fail("��ľ����޷����У�\n");
        if( !arg )
                return notify_fail("��ҪΪ˭�ƶ���\n");
        if ( arg == "spirit" )
        {       me->receive_damage("sen",50);
                message_vision(HIC"$N˫�ƺ�ʮ������"NOR+HIY"���鵶"NOR+HIC"��Ĭ�����\n"NOR, me);
                      me->clear_condition();  
                 write("��ɹ����������ڶ��أ�\n");
                      return 1;  
          }
}
 
int do_summons(string arg)
{
        object me = this_player ();
       object ob;
 
       if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в����ٻ����飡\n");
       if( (int)me->query("sen") < 400 )
                return notify_fail("��ľ����޷����У�\n");

       message_vision(HIY"$N"+HIY"�����鵶һ�ӣ��૵����˼������\n"NOR, me);

       me->receive_damage("sen", 80);
       ob = new("/d/quest/tulong/npc/spirit");
       ob->move(environment(me));
       ob->invocation(me); 
       return 1;
} 

int do_change(string arg)
{     
        object me = this_player();   
        object ob = this_object();
        object obj;
        if( (int)me->query("sen") < 200 )
                return notify_fail("��ľ����޷����У�\n");
        if( arg == "sword")
        { 
                me->receive_damage("sen",100);
              message_vision(HIC"$N����"NOR+HIY"���鵶"NOR+HIC"����һ�Σ������һ�ѽ���\n"NOR, me); 
                  obj=new("/d/quest/tulong/obj/sword");
                  obj->move(me);   
                  destruct(ob);
                  return 1;  
        }
          return 0;
}


