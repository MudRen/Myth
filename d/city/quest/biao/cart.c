//Last Create By PKYOU@DHXY 2002/05/30
#include <ansi.h>
inherit ITEM;

void to_rob();

mapping default_dirs = ([
        "north":        "����",
        "south":        "����",
        "east":         "����",
        "west":         "����",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "����",
        "down":         "����",
        "enter":        "����",
        "out":          "����",
]);
void create()
{       
        seteuid(getuid());
        set_name(HIR"�ڳ�"NOR, ({ "biao che", "cart", "che"}) );
        set_weight(300000);
        set("no_get", 1);
 
set("location",1);
set("no_clean_up",1);

        set_max_encumbrance(80000000);
        set("unit", "��");
        set("long", "һ����������ڳ�������������졣\n");
        set("closed", 1);
        set("value", 2000);
    
}

void init()
{
    add_action("do_open","jie");
    if( this_player()->query_temp("in_dart"))
    {
         add_action("do_gan","gan"); 
         add_action("do_gan","drive");
    }
    call_out("destroy2",random(800)+1000,this_object());
}

int do_open(string arg)
{
        object me, ob;
        string mname,mid;
        mname = this_object()->query("master");
        mid = this_object()->query("masterid");
        me = this_player();
        ob = this_object();

        if(arg != "biao che")
          return notify_fail("��Ҫ��ʲô��\n");
        if(me->query_temp("in_dart"))
          return notify_fail("��������Ե���\n"); 
        if(present(mid,environment()))
          return notify_fail("���ڵĻ����Աߣ��Ȱ��������ɡ�\n");

        message_vision("$N��$n�����ˡ�\n", me, this_object());
        message("channel:rumor",YEL"���{�Ի��ڡ�"+mname
         +"�������ڳ���"+me->query("name")+"��ȥ�ˣ�\n"NOR,users());
        call_out("destroy1",1,ob);
        return 1;
}

int do_gan(string arg)
{        
        object me,ob, env, obj, ob_robber;
        string item, dir, dest, target;
        mapping exit;
        me = this_player();
        ob = this_object();

        if(!arg) return notify_fail("��Ҫ��ʲô��\n");

        if( me->query("id")!=ob->query("masterid")) return 0;
        
        if( sscanf(arg, "%s to %s", item, dir) != 2 ||
                item != "cart" && item != "che")
                return command(query_verb()+" "+arg);
                        
        if( me->is_busy() )
                return notify_fail("��������æ������\n");

        if ( ob_robber = present("robber",environment()))
                if(ob_robber->query("masterid") == me->query("id"))
                        return notify_fail("�ٷ�����һ�����������ܣ�û��ô���ף���\n");
        
        if ( this_player()->is_fighting())
                return notify_fail("�㻹���ȰѶ��ֽ������˵�ɣ�\n");
 
        env = environment(me);
        if(!env) return notify_fail("��Ҫȥ���\n");
        
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) {
                if( query_verb()=="gan")
                        return notify_fail("����������ȥ��\n");
                else
                        return 0;
        }
        
        dest = exit[dir];
                        
        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("û���ϡ�\n");

        if( !undefinedp(default_dirs[dir]) )
                target = default_dirs[dir];
        else
                target = obj->query("short");

        message_vision(HIG "\n$N�����ڳ���" + target + "ʻȥ��\n" NOR,
                me);
        message_vision(HIG "�ڳ�¡¡��"+ target + "ʻȥ��\n" NOR,me);  

        if( ob->move(obj) && me->move(obj)) {
          all_inventory(env)->follow_me(me, dir);
          message_vision(HIG "$N�����ڳ�ʻ�˹�����\n" NOR,
                        me);
          message_vision(HIG "�ڳ�¡¡ʻ�˹�����\n" NOR,me); 
          me->start_busy(random(3));
        }
        call_out("check1",1,ob,me);
        if (random(10)>4){ call_out("to_rob",1,me);}
        return 1;
}
int check1(object ob, object me)
{
        if (base_name(environment())==(string)me->query_temp("dart_area") 
             && present(me->query_temp("dart_id"), environment()) )
           {  
              message_vision("$N���˸����������ڰ����˵��˵�ͷ��\n\n",me);
              message_vision(HIG+me->query_temp("dart_name")+
                "����$N�ļ��˵������"+RANK_D->query_respect(this_player())
                +"�����ˣ���\n\n"NOR,me);
              write(HIG"�����������˽��ڳ����˽�ȥ��\n"NOR);
              me->set_temp("over_dart",1);
              me->apply_condition("dart_limit", 0);
              call_out("destroy1",1,ob);
              return 1;
            }  
}
void destroy1(object me)
{
        
        destruct(me);
        return;
}

void destroy2(object me)
{
     message_vision("ͻȻ���Ӵ��һ�������������ڳ����ˡ�\n",me);
  destruct(me);
  return;
}

void to_rob()
{
  object *ob;
  object robber,biaoshi,room;
  int i, n;
  room = environment(this_player());
  
  
  if(room->query("short") == "���ǵ���" || room->query("short") == "���Ǯׯ" || room->query("short") == "���õ���"
  || room->query("short") == "���⵱��" || room->query("short") == "��ҵ���" || room->query("short") == "����Ǯׯ"
  || room->query("short") == "�ż�Ǯׯ") return;
  if( environment(this_player())->query("no_fight") ) return;
        ob = all_inventory(environment(this_player()));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i])) continue;
                                ob[i]->set_leader(0);
                }
  this_player()->start_busy(2);
  
  robber=new (__DIR__"npc/robber");
  robber->set("masterid",query("masterid"));
  robber->do_change(this_player());
  robber->move(room);
  robber->kill_ob(this_player());
  robber->checking(robber,this_player());
  robber->set_leader(this_object());
  robber->command("rob");

message_vision(HIR"ͻȻ����һ������Ϊ�׵�ͷ����е���������������·Ǯ������\n" NOR,
        this_player()); 
            
    for(n=0; n<1+random(4); n++) {
    biaoshi = new (__DIR__"npc/biaotou");
    biaoshi->move(room);
    biaoshi->set_leader(robber);
    biaoshi->command("heng");
    biaoshi->kill_ob(robber);
    }

}
