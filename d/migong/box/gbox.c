// ����

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
string *box_object=({
"item/0",
"item/1",
"item/2",
"item/3",
"item/4",
"item/5",
"item/6",
"item/7",
"item/8",
"item/9",
"item/10",
"item/11",
"item/12",
"item/13",
"item/14",
"item/15",
"item/16",
"item/17",
"item/18",
"item/19",
"item/20",
"item/21",
"item/22",
"item/23",
"item/24",
"item/25",
"item/26",
"item/27",
"item/28",
"item/29",
"item/30",
"item/31",
"item/32",
"item/33",
"item/34",
"item/35",
"item/36",
"item/37",
"item/38",
"item/39",
"item/40",
"item/41",
"item/42",
"item/43",
"item/44",
"item/45",
"item/46",
"item/47",
"item/48",
"item/49",
"item/50",
"item/51",
"item/52",
"item/53",
"item/54",
"item/55",
"item/56",
"item/57",
"item/58",
"item/59",
"item/60",
"item/61",
"item/62",
"item/63",
"item/64",
"item/65",
"item/66",
"item/67",
"item/68",
"item/69",
"item/70",
"item/71",
"item/72",
"item/73",
"item/74",
"item/75",
"item/76",
"item/77",
"item/78",
"item/79",
"item/80",
"item/81",
"item/82",
"item/83",
"item/84",
"item/85",
"item/86",
"item/87",
"item/88",
"item/89",
"item/90",
"item/91",
"item/92",
"item/93",
"item/94",
"item/95",
"item/96",
"item/97",
"item/98",
"item/99",
"item/100",
"item/101",
"item/102",
"item/103",
"item/104",
"item/105",
"item/106",
"item/107",
"item/108",
"item/109",
"item/110",
"item/111",
"item/112",
"item/113",
"item/114",
"item/115",
"item/116",
"item/117",
"item/118",
"item/119",
"item/120",
"item/121",
"item/122",
"item/123",
"item/124",
"item/125",
"item/126",
"item/127",
"item/128",
"item/129",
"item/130",
"item/131",
"item/132",
"item/133",
"item/134",
"item/135",
"item/136",
"item/137",
"item/138",
"item/139",
"item/140",
"item/141",
"item/142",
"item/143",
"item/144",
"item/145",
"item/146",
});
             

void create()
{
        set_name(HIG"����"NOR, ({"bao xiang", "bao", "xiang"}));
        set("no_get",1);
        set_weight(100000);
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���ú�ľ�������ɵ�"+HIG"���䣬"NOR+"�ƺ����Դ�(openbox)��\n");
                set("unit", "��");
                set("value", 0);
        }
}


void init()
{
   add_action("do_open","openbox");
}

   

int do_open(string arg)
{ 
    object me=this_player(),ob,corpse;
    if(me->query("gender")=="����")
        tell_object(me,"���Ȳ������ؽ�"+HIG+"����"NOR+"�򿪣�\n");
    else
        tell_object(me,"��С������ؽ�"+HIY+"����"NOR+"�򿪣�\n");

    if( me->over_encumbranced() )
        return notify_fail("���ϴ��Ķ���̫���ˣ��ò����ˡ�\n");

    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
    {
        if (random(60) < 1 && environment(me)->query("short")!=CYN"ʯ��"NOR
        && !environment(this_object())->query("alrd"))
        {
                 corpse=new("/d/quest/baoshi/baoshi");
                 message_vision("$N�õ�һ���������ı�ʯ��\n",me);
                 message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�������Թ����ҵ���һ��"+corpse->query("name")+HIM"!"NOR"��\n", users());
                 corpse->move(me);
                 environment(this_object())->set("alrd",1);

        }
    }
    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
    {
        if (random(70) < 1 && environment(me)->query("short")!=CYN"ʯ��"NOR
        && !environment(this_object())->query("alrd"))
        {
             corpse=new("/d/migong/box/ring"+random(10));
             message_vision("$N�õ�һ���������Ľ�ָ��\n",me);
             message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�������Թ����ҵ���һö"+corpse->query("name")+HIM"!"NOR"��\n", users());
             corpse->move(me);
             environment(this_object())->set("alrd",1);

        }
    }

      if(random(100)>85)
      {
        tell_object(me,"���ʲôҲû�С�\n"NOR);
      }
      else if(random(100)>95)
      {
        ob=new("/obj/money/gold");
        ob->set_amount(random(100));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"�ƽ�"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/obj/money/gold");
        ob->set_amount(random(100));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"�ƽ�"NOR+"��\n"NOR);
      }  
      else if(random(200)>180)
      {
        me->add("shen",-50);
        me->add("kee",-100);
        tell_object(me,"�����﷢������"+HIR"����,��������!"NOR+"��\n"NOR);
      }  
      else if(random(200)>180)
      {
        me->add("shen",-50);
        me->add("kee",-100);
        tell_object(me,"�����﷢������"+HIR"����,��������!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("snake_poison",10);
        me->add("kee",-10);
        tell_object(me,"�����﷢������"+RED"����,�������߶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("rose_poison",10);
        me->add("kee",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˻�õ�嶾!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("hell_zhua",10);
        me->add("kee",-10);
        tell_object(me,"�����﷢������"+RED"����,������ʬ��!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("bp_poison",10);
        me->add("kee",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˱���!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("double_ice_poison",10);
        me->add("kee",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˺���!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("xiangsi",10);
        me->add("kee",-10);
        tell_object(me,"�����﷢������"+RED"����,�������鶾!"NOR+"��\n"NOR);
      }  
      else if(random(300)>298)
      {
        tell_object(me,"�����﷢��һ��"+HIY"����,��ʲôҲ��֪����!"NOR+"��\n"NOR);
        me->unconcious();
      }  
      else if(random(300)>298)
      {
        tell_object(me,"�����﷢��һ��"+HIR"Ѫ��,��������鲻����!!"NOR+"��\n"NOR);
        me->die();
      }  
      else if(random(200)>198 && environment(me)->query("short")==BLU"ɽ��"NOR)
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,��ľ���͵���������!!"NOR+"��\n"NOR);
        me->add("combat_exp", 1000);
        me->add("daoxing",1000);
      }  
      else if(random(200)>198 && environment(me)->query("short")==WHT"����ʯ��"NOR)
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,���Ǳ��������!!"NOR+"��\n"NOR);
        me->add("potential",200);        
      }  
      else if(random(200)>198 && environment(me)->query("short")==YEL"�Ҷ�"NOR)
      {
        tell_object(me,"�����﷢��һ����͵�"+YEL"���,��������ͷ���������!!"NOR+"��\n"NOR);
        me->add("max_force",10);
        me->add("max_mana",10);
      }  
      else if(random(200)>198 && environment(me)->query("short")==RED"���Ҷ�"NOR)
      {
        tell_object(me,"�����﷢��һ����͵�"+YEL"���,��ľ��飬���У�Ǳ�ܣ������ͷ�����������!!"NOR+"��\n"NOR);
        me->add("combat_exp", 800);
        me->add("daoxing",800);
        me->add("potential",100);        
        me->add("max_force",10);
        me->add("max_mana",10);
      }  
      else if(random(200)>198 
      && !environment(this_object())->query("alrd"))
      {
          if (  environment(me)->query("short")==RED"���Ҷ�"NOR
             || environment(me)->query("short")==YEL"�Ҷ�"NOR)
          {
              tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ�Ż�����!!"NOR+"��\n"NOR);
              ob=new(__DIR__"zhu7");
              ob->move(me);
              environment(this_object())->set("alrd",1);
          }
      }  
      else if(random(200)>198 && environment(me)->query("short")==BLU"ɽ��"NOR)
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ��������!!"NOR+"��\n"NOR);
          ob=new(__DIR__"zhu1");
          ob->move(me);
      }  
      else if(random(200)>198 && environment(me)->query("short")==BLU"ɽ��"NOR
      && !environment(this_object())->query("alrd"))
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ�Ż�����!!"NOR+"��\n"NOR);
          ob=new(__DIR__"baowu/huozhu");
          ob->move(me);
          environment(this_object())->set("alrd",1);
      }  
      else if(random(200)>198 && environment(me)->query("short")==WHT"����ʯ��"NOR)
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ��������!!"NOR+"��\n"NOR);
          ob=new(__DIR__"zhu2");
          ob->move(me);
      }  
      else if(random(200)>198 && environment(me)->query("short")==WHT"����ʯ��"NOR
      && !environment(this_object())->query("alrd"))
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ��������!!"NOR+"��\n"NOR);
          ob=new(__DIR__"baowu/leizhu");
          ob->move(me);
          environment(this_object())->set("alrd",1);
      }  

      else if(random(200)>198 && environment(me)->query("short")==YEL"�Ҷ�"NOR)
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ�Ÿ�����!!"NOR+"��\n"NOR);
          ob=new(__DIR__"zhu3");
          ob->move(me);
      }  
      else if(random(200)>198 && environment(me)->query("short")==YEL"�Ҷ�"NOR
      && !environment(this_object())->query("alrd"))
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ��������!!"NOR+"��\n"NOR);
          ob=new(__DIR__"baowu/tuzhu");
          ob->move(me);
          environment(this_object())->set("alrd",1);
      }  

      else if(random(200)>198 && environment(me)->query("short")==RED"���Ҷ�"NOR      )
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ������!!"NOR+"��\n"NOR);
          ob=new(__DIR__"zhu4");
          ob->move(me);
      }  
      else if(random(200)>198 && environment(me)->query("short")==RED"���Ҷ�"NOR
      && !environment(this_object())->query("alrd"))
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ�ŷ�����!!"NOR+"��\n"NOR);
          ob=new(__DIR__"baowu/fengzhu");
          ob->move(me);
          environment(this_object())->set("alrd",1);
      }  

      else if(random(200)>198 && environment(me)->query("short")==RED"���Ҷ�"NOR)
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ����ò��!!"NOR+"��\n"NOR);
          ob=new(__DIR__"zhu6");
          ob->move(me);
      }  

      else if(random(200)>198 && environment(me)->query("short")==YEL"�Ҷ�"NOR)
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ�Ÿ�Ե��!!"NOR+"��\n"NOR);
          ob=new(__DIR__"zhu5");
          ob->move(me);
      }  
      else if(random(200)>198 && environment(me)->query("short")==YEL"�Ҷ�"NOR
      && !environment(this_object())->query("alrd"))
      {
          tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ��ˮ����!!"NOR+"��\n"NOR);
          ob=new(__DIR__"baowu/shuizhu");
          ob->move(me);
          environment(this_object())->set("alrd",1);
      }  

      else if(random(100)>95)
      {
          ob=new("/obj/money/silver");
          ob->set_amount(random(150));
          ob->move(me);
          tell_object(me,"������һЩ"+HIY"����"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
          ob=new("/obj/money/silver");
          ob->set_amount(random(150));
          ob->move(me); 
          tell_object(me,"������һЩ"+HIY"����"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
          ob=new("/obj/money/silver");
          ob->set_amount(random(150));
          ob->move(me);
          tell_object(me,"������һЩ"+HIY"����"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
          ob=new("/obj/money/coin");
          ob->set_amount(random(1000));
          ob->move(me);
          tell_object(me,"������һЩ"+HIY"ͭǮ"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
          ob=new("/obj/money/coin");
          ob->set_amount(random(1000));
          ob->move(me);
          tell_object(me,"������һЩ"+HIY"ͭǮ"NOR+"��\n"NOR);
      }  
      else
      {
           int rand;
           rand=random(sizeof(box_object));
           ob=new(__DIR__+box_object[rand]);
           if(ob)
           {
               ob->move(me);
               ob->move(me);
               tell_object(me,"������"+HIY":"+ob->query("name")+"."NOR+"��\n"NOR);
           }
           else            tell_object(me,"���ʲôҲû��!"NOR+"��\n"NOR);
      }  
        destruct(this_object());         
        return 1;
}

