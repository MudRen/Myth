#include <ansi.h>
#include <room.h>

inherit ROOM;
int opp=0;
int dm=100000000;
void create (int level,int num)
{
  set ("short", HIG "魔风岭石门" NOR);
  set ("long", @LONG
一扇巨大的石门在眼前，抬头远望过去看到魔风岭蔚然耸立的山头。
看来要打开这个石门是颇费工夫的。
LONG);
     level=10; num=random(2)+1;
    set("exits", ([

            "northup" : __DIR__"shan1",
                                 ]));
        set("level",level);//自己可以设定！
        set("alternative_die",1);
        set("mofengroom",1);
        set("npc_npc",num);//自己可以设定！
        set("objects",([
        "/d/quest/mofeng/npc/tudi" : 1,

                 ]));

  setup();


}

void init()
{

    add_action("do_break", "break");

}
void do_check(object who)
{
        object env,*inv;
        int i,count,dm,fa;
        env=this_object();
        inv = all_inventory(env);
        if (env->query("open_time") && env->query("open_time")+3 > time())
               {
          message_vision("$N尝试用力推了一下，石门纹丝未动！\n" +NOR,who);
          return;}

       env->set("open_time",time());

       fa=0;count=0;
       for (i=0;i<sizeof(inv);i++)
       {
       if (!userp(inv[i])) continue;
       if (inv[i]->query_temp("allow_tudi"))
        {
        count ++;
        fa +=inv[i]->query("force_factor");
        inv[i]->receive_wound("kee", 100*(random(3)+2));
        inv[i]->receive_damage("sen",100*(random(3)+2));
        if (inv[i]->query("force")>300) inv[i]->add("force",300);
        if (inv[i]->query("mana")>300) inv[i]->add("mana",300);
      message_vision("$N用很大内力推了一下，累的半死，石门向后移动了几下！！\n" +NOR,who);

        }
       }

       dm -=(count-3)*fa;
       if (dm < 0)
       { message("system",HIG+"顿时鬼哭神嚎，地动山摇！魔风岭之门终于打开了！\n" +NOR,users());
       env->set("opened",1);

       dm=100000000;
       }

}

int do_break(string arg)
{
       object who ;
         who=this_player();
       if (this_object()->query("opened"))
          {
          tell_object(who,"土地公公说，石门不是开吗？\n");
          return 1;
          }

       if (!who->query_temp("allow_tudi"))
        {
        tell_object(who,"土地公公说，你急什么，你真的要进去吗？\n");
        return 1;
        }
       if (arg!="door")
       {
       tell_object(who,"土地公公说，你敲什么吗？\n");
        return 1;
        }
       if (opp==0)
       {
       message("system",HIG+who->name()+"力图打开魔风岭之门，众神请祝$n一力！\n" +NOR,users(),who);
       opp ++;

       }
               do_check(who);

       return 1;

}


void alternative_die(object who)
{
    object killer,corpse;
    killer = who->query_temp("last_damage_from");

    if (userp(who))
    {
        message_vision("$N死了。\n",who);
        who->set("kee",100);
        who->set("sen",100);
        if (who->query("eff_kee") < 10)
            who->set("eff_kee",100);
        if (who->query("eff_sen") < 10)
            who->set("eff_sen",100);


    }
    else
    {
        if (objectp(corpse = CHAR_D->make_corpse(who, killer)))
            corpse->move(this_object());
        message_vision("$N死了。\n",who);

        destruct(who);
    }
}



int valid_leave (object who, string dir)
{
  object where = this_object ();
  object obj = present ("tudi",where);


 if (dir=="northup")
        {
  if (!who->query_temp("allow_tudi") )
    return notify_fail ( obj->name()+"说，："+who->name()+"!此地危险，请回吧！\n");
  if (!where->query("opened"))
      return notify_fail("石门未开，你过不去。\n");
        }
  return ::valid_leave (who, dir);
}

