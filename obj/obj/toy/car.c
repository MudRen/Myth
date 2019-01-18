// by snowcat 5/3/1997

#include <ansi.h>

inherit ITEM;

mapping chinese_dirs = ([
  "north":        "��",
  "south":        "��",
  "east":         "��",
  "west":         "��",
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
  ]);

mapping left_dirs = ([
  "north":        "northwest",
  "south":        "southeast",
  "east":         "northeast",
  "west":         "southwest",
  "northeast":    "north",
  "northwest":    "west",
  "southeast":    "east",
  "southwest":    "south",
  ]);

mapping right_dirs = ([
  "north":        "northeast",
  "south":        "southwest",
  "east":         "southeast",
  "west":         "northwest",
  "northeast":    "east",
  "northwest":    "north",
  "southeast":    "south",
  "southwest":    "west",
  ]);

string *makes = ({
  "Acura NXL",
  "Audi Cabriolet",
  "BMW 850",
  "Buick Skylark",
  "Cadillac Seville",
  "Chevrolet Monte Carlo",
  "Chrysler Sebring Convertable",
  "Dodge Viper",
  "Eagle Vision",
  "Ford Thunderbird",
  "Geo Metro",
  "Honda Accord",
  "Hyundai Sonata",
  "Infinti Q45",
  "Jaguar",
  "Lexus SC400",
  "Lincoln Towncar",
  "Mazda Protege",
  "Mercedes-Benz SLK-CLASS",
  "Mercury Tracer",
  "Mitsubishi Mirage",
  "Nissan Maxima",
  "Oldsmobile Aurora",
  "Plymouth Neon",
  "Pontiac Sunfire",
  "Porsche Boxster",
  "Saab 9000",
  "Saturn",
  "Subaru Legacy",
  "Suzuki Esteem",
  "Toyota Camry",
  "Volksvagon Passat",
  "Volvo 960",
  });

void create()
{
  string name = makes[random(sizeof(makes))]+" �γ�";

  set_name(name, ({"car", "che"}));
  set_weight(300000);
  set_max_encumbrance (1000000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("short", name+"(Car)");
    set("long", "����һ��"+name+"��\n");
    set("unit", "��");
    set("material", "metal");
    set("value", 1000000);
    set("dir", "north");
    set("speed", 0);
    set("fuel", 10000);
    set("miles", 0);
  }
  setup();
}

void automate();

int init()
{
  add_action("do_enter", "enter");
  add_action("do_out", "out");
  add_action("do_look", "look");
  add_action("do_left", "4");
  add_action("do_right", "6");
  add_action("do_speedup", "8");
  add_action("do_slowdown", "2");
  add_action("do_stop", "5");
  add_action("do_handdrive", "7");
  add_action("do_autodrive", "9");
  automate();
  return 1;
}

int test_busy ()
{
  object me = this_object();
  object who = this_player();

  if (me->query_temp("is_busy"))
  {
    tell_object (who,"������̫�ͣ����ӻ�㻵�ģ�\n");    
    return 1;
  }
  me->set_temp("is_busy",1);
  remove_call_out ("reset_busy_temp");
  call_out ("reset_busy_temp",1,me);
  return 0;
}

void reset_busy_temp (object me)
{
  me->set_temp("is_busy",0);  
}

int is_in ()
{
  object me = this_object();
  object who = this_player();
  return environment(who) == me; 
}

int is_driver ()
{
  object me = this_object();
  object who = this_player();

  if (me->query("driver") != who)
  {
    tell_object (who,"���Ҷ������ֲ���˾����\n");  
    return 0;
  }
  return 1;
}

int report_outside_objects ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);
  mixed *inv = all_inventory(where);
  int i;

  if (sizeof(inv) <= 1)
    return 1;

  tell_object (who,"�����У�");  
  for (i=0; i < sizeof(inv); i++)
  {
    if (inv[i] != me)
      tell_object (who,inv[i]->query("name")+"("+inv[i]->query("id")+") ");    
  }
  tell_object (who,"\n");  
  return 1;
}

int report_inside_objects ()
{
  object me = this_object();
  object who = this_player();
  mixed *inv = all_inventory(me);
  int i;

  if (sizeof(inv) == 0)
    return 1;

  tell_object (who,"�����У�");  
  for (i=0; i < sizeof(inv); i++)
  {
    tell_object (who,inv[i]->query("name")+"("+inv[i]->query("id")+") ");    
  }
  tell_object (who,"\n");  
  return 1;
}

int report_dir ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);
  mapping exits = where->query("exits");
  string *dirs;
  int i;

  if (! exits)
    return 1;

  dirs = keys(exits);

  tell_object (who,"����ĳ����ǣ�");  
  for (i=0; i < sizeof(dirs); i++)
  {
    tell_object (who,chinese_dirs[dirs[i]]+"("+dirs[i]+")");    
  }
  tell_object (who," [��ͷ����"+chinese_dirs[me->query("dir")]+
                   "("+me->query("dir")+")]\n");  
  return 1;
}

int report_view ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  tell_object (who,"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n");  
  tell_object (who,"�ӳ�������Կ�����");  
  tell_object (who,where->query("short")+"\n");  
  tell_object (who,where->query("long")+"\n");  
  report_outside_objects();
  report_dir();
  tell_object (who,"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n");  
  return 1;
}

int report_short ()
{
  object me = this_object();
  object who = this_player();
  string strspeed, strfuel, strmiles;
  int i, len = 15;

  strspeed = "�ٶȣ�"+sprintf("%d",me->query("speed"));
  strfuel  = "���ͣ�"+sprintf("%d",me->query("fuel")) ;
  strmiles = "��̣�"+sprintf("%d",me->query("miles"));
  for (i = sizeof(strspeed); i < len; i++)
    strspeed = strspeed + " ";
  for (i = sizeof(strfuel); i < len; i++)
    strfuel = strfuel + " ";
  for (i = sizeof(strmiles); i < len; i++)
    strmiles = strmiles + " ";
  tell_object (who,"\n");  
  tell_object (who,"  ��������������������������������������������\n");  
  tell_object (who,"  ��"+ strspeed + " 7[�ֵ�] 8[����] 9[�Ե�] ��\n");  
  tell_object (who,"  ��"+ strfuel  + " 4[��ת] 5[ɲ��] 6[��ת] ��\n");  
  tell_object (who,"  ��"+ strmiles + "         2[����]         ��\n");  
  tell_object (who,"  ��������������������������������������������\n");  
  if (me->query("autodrive") > 0)
    tell_object (who,"  ������ƣ�ȫ�Զ�");  
  else
    tell_object (who,"  ������ƣ��ֶ�");  
  if (me->query("driver"))
    tell_object (who,"  ˾����"+me->query("driver")->query("name"));  
  tell_object (who,"\n");  
  report_inside_objects();
  return 1;
}

int do_enter (string arg)
{
  object me = this_object();
  object who = this_player();

  if (arg != "car")
    return 0;

  if (is_in())
    return 0;

  if (me->query("speed") > 0)
  {
    tell_object (who,"����������ʻ�ĳ��ӻ�������Σ�գ�\n");  
    return 1;
  }

  message_vision ("$Nһ��������������\n",who);
  who->move(me);
  if (! me->query("driver") ||
      environment(me->query("driver")) != me)
  {
    me->set("driver",who);
    message_vision ("$N����˾����λ�ϡ�\n",who);
  }
  else
    message_vision ("$N���ڿ����ϡ�\n",who);
  return 1;
}

int do_out (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! is_in())
    return 0;

  if (me->query("speed") > 0)
  {
    tell_object (who,"����������ʻ�ĳ��ӻ�������Σ�գ�\n");  
    return 1;
  }

  if (me->query("driver") == who)
  {
    me->set("driver",0);
  }

  message_vision ("$Nһ�򿪳������³���\n",who);
  who->move(environment(me));
  message_vision ("$N�������������Ź��ϡ�\n",who);
  return 1;
}

int do_look (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! is_in())
  {
    if (arg == "car")
    {
      tell_object (who,"����һ"+me->query("unit")+me->query("name")+
                   "(enter)��\n");
      return 1;
    }
    return 0;
  }
  report_view();
  report_short();
  return 1;
}

int do_left (string arg)
{
  object me = this_object();
  object who = this_player();
  string dir = me->query("dir");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (me->query("speed") == 0)
  {
    tell_object (who,"�Ƚ����ӷ���������ת�䡣\n");
    return 1;  
  }

  dir = left_dirs[dir];
  tell_object (who,"�㽫����������һת��\n");  
  message_vision (me->query("name")+"��ͷ��"+chinese_dirs[dir]+
                  "һ�ա���\n",me);
  me->set("dir",dir);
  return 1;
}

int do_right (string arg)
{
  object me = this_object();
  object who = this_player();
  string dir = me->query("dir");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (me->query("speed") == 0)
  {
    tell_object (who,"�Ƚ����ӷ���������ת�䡣\n");
    return 1;  
  }

  dir = right_dirs[dir];
  tell_object (who,"�㽫����������һת��\n");  
  message_vision (me->query("name")+"��ͷ��"+chinese_dirs[dir]+
                  "һ�ա���\n",me);
  me->set("dir",dir);
  return 1;
}

int do_speedup (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (s == 0)
  {
    s += 2+random(4);
    tell_object (who,"���𷢶����ӡ�\n");  
    message_vision (me->query("name")+"�����һ�����������³�һ������\n",me);
  }
  else if (s < 45)
  {
    s += 4+random(8);
    tell_object (who,"�����һ�����š�\n");  
    message_vision (me->query("name")+"����ؼ��١�\n",me);
  }
  else if (s < 90)
  {
    s += 8+random(16);
    tell_object (who,"����������һ�����š�\n");  
    message_vision (me->query("name")+"ವ�һ���ӿ���ʱ�٣�\n",me);
  }
  else 
  {
    s += 16+random(32);
    tell_object (who,"��ʹ�����˲���һ�����š�\n");  
    message_vision (me->query("name")+"�����Ƶؼ��٣�\n",me);
  }
  if (s > 320)
    s = 320;
  me->set("speed",s);
  return 1;
}

int do_slowdown (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (s == 0)
  {
    tell_object (who,"�����Ѿ�ͣ�ˡ�\n");  
  }
  else if (s < 45)
  {
    s -= 4+random(8);
    tell_object (who,"������ز��˲�բ��\n");  
    message_vision (me->query("name")+"�������١�\n",me);
  }
  else if (s < 90)
  {
    s -= 8+random(16);
    tell_object (who,"����˲�բ��\n");  
    message_vision (me->query("name")+"���Ե�����������\n",me);
  }
  else 
  {
    s -= 16+random(32);
    tell_object (who,"��ʹ���ز���һ��բ��\n");  
    message_vision (me->query("name")+"�ڷɳ��м��١�\n",me);
  }
  if (s < 0)
    s = 0;
  me->set("speed",s);
  return 1;
}

int do_stop (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (s == 0)
  {
    tell_object (who,"�����Ѿ�ͣ�ˡ�\n");  
  }
  else if (s < 20)
  {
    s = 0;
    tell_object (who,"���͵�һɲ����\n");  
    message_vision (me->query("name")+"����һ�ߣ�ͣ�ˡ�\n",me);
  }
  else if (s < 45)
  {
    s = 0;
    tell_object (who,"��һ����ɲ����\n");  
    message_vision (me->query("name")+"ͻȻ����ؼ��٣�\n",me);
    message_vision (me->query("name")+"����һ�������ļ�У�֨һ��ͣ�ˣ�\n",me);
    tell_object (who,"���͵�����һ�£�\n");  
  }
  else if (s < 100)
  {
    s -= 40+random(40);
    tell_object (who,"����ز�բ��ɲ����\n");  
    message_vision (me->query("name")+"ͻȻ����ؼ��٣�\n",me);
    message_vision (me->query("name")+"���ҵ����ţ�\n",me);
    tell_object (who,"��һ��ͷ�Σ���һ�����˳�����\n");  
  }
  else 
  {
    s -= 60+random(60);
    tell_object (who,"�㲻��һ�еصز�բ��ɲ����\n");  
    message_vision (me->query("name")+"ͻȻ����ؼ��٣�\n",me);
    message_vision (me->query("name")+"���µ����ţ����ϻ���������ӡ��\n",me);
    tell_object (who,"ǿ�ҵ�������һ�����ͷʹ��\n");  
    //who->unconcious();
  }
  if (s < 0)
    s = 0;
  me->set("speed",s);
  return 1;
}

int do_handdrive (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  me->set("autodrive",0);
  tell_object (who,"�����ֶ������г�����\n");  
  return 1;
}

int do_autodrive (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  me->set("autodrive",1);
  tell_object (who,"����ȫ�Զ������г�����\n");  
  return 1;
}

void collision ()
{
  object me = this_object();
  object who = me->query("driver");
  int s = me->query("speed");
  string *hits = ({
    "�����·",
    "����·�ߵĲݴ���",
    "ײ��һ��������",
    "����һ̲����",
    "����һ��Сľ��",
    "����һ��Թ�ľ��",
    "ײ��һƬС��",
  });
  string how;

  if (s == 0)
    how = "�����";
  else if (s < 20)
    how = "�۵�һ��";
  else if (s < 40)
    how = "����һ��";
  else if (s < 60)
    how = "���һ��";
  else if (s < 80)
    how = "���һ��";
  else if (s < 100)
    how = "������Ұ��һ����";
  else if (s < 150)
    how = "������";
  else 
    how = "�������Ѱ��";

  if (s < 50)
  {
    message_vision (me->query("name")+how+hits[random(sizeof(hits))]+
                    "��\n",me);
    message_vision (me->query("name")+"ͣ��������\n",me);
  }
  else if (s < 100)
  {
    message_vision (me->query("name")+how+hits[random(sizeof(hits))]+
                    "��\n",me);
    message_vision (me->query("name")+"��һ��ǿ�ҵ�����ͣ��������\n",me);
    tell_object (who,"��һ��Ŀѣ��\n");  
  }
  else
  {
    message_vision (me->query("name")+how+hits[random(sizeof(hits))]+
                    "��\n",me);
    message_vision (me->query("name")+"��һ�󼫿��µ����з������죡\n",me);
    message_vision ("һ����ͻȻ����������ͣ��������\n",me);
    tell_object (who,"��һɲ�Ǿ��ô�������ж��������͵�������ͻȻֹͣ��\n");  
    //who->unconcious();
  }
  me->set("speed",0);
}

void display_me ()
{
  object me = this_object();
  string name = me->query("name");
  int s = me->query("speed");
  string msg = 0;

  if (s == 0)
  {
    set("short", "ͣ��·�ϵ�"+name+"(Car)");    
  }
  else if (s < 30)
  {
    set("short", "������ʻ��"+name+"(Car)");
    msg = name+"������ʻ�š�\n";
  }
  else if (s < 50)
  {
    set("short", "��ʻ�е�"+name+"(Car)");
    msg = name+"������ʻ�š�\n";
  }
  else if (s < 110)
  {
    set("short", "��ʻ��"+name+"(Car)");
    msg = name+"�ɿ����ʻ�š�\n";
  }
  else 
  {
    set("short", "��ʻ�е�"+name+"(Car)");
    msg = name+"�����Ƶؿ�ʻ�š�\n";
  }
  if (msg && 
      random(10) == 0)
    message_vision (msg,me);
}

void check_speed ()
{
  object me = this_object();

  if (me->query("speed") > 0 &&
      me->query("fuel") <= 0)
  {
    me->set("speed",0);
    message_vision (me->query("name")+"��ֵ�ð��һ�����̣�û��ȼ���ˡ�\n",me);
    message_vision (me->query("name")+"����������ͣ�ˡ�\n",me);
  }

  if (me->query("speed") > 0 &&
      (! me->query("driver") ||
        environment(me->query("driver")) != me))
  {
    me->set("speed",0);
    message_vision (me->query("name")+"û��˾���ˡ�\n",me);
    message_vision (me->query("name")+"֨��һ������бб��ͣ�ˡ�\n",me);
  }
}

void check_fuel ()
{
  object me = this_object();

  if (me->query("speed") > 0 &&
      me->query("fuel") > 0)
  {
    int f = me->query("fuel");

    f -= (me->query("speed")/10+1); 
    if (f < 0)
      f = 0;
    me->set("fuel",f);
  }
}

void check_miles ()
{
  object me = this_object();

  if (me->query("speed") > 0)
  {
    me->add("miles",me->query("speed")/6);
  }
}

object find_room (string dest)
{
  object me = this_object();
  object where = environment(me);

  if (!dest)
    return 0;
  return find_object(dest);
}

object find_exit ()
{
  object me = this_object();
  object where = environment(me);
  object who = me->query("driver");
  string dir = me->query("dir");
  object obj = 0;
  mapping dirs;
  string dest;

  if (!mapp(dirs = where->query("exits")))
  {
    tell_object (who,"�������û��ʲô·�����ˡ�\n");
    return 0;  
  }

  while (obj == 0)
  {
    dest = dirs[dir];
    if (dest)
      obj = find_room(dest);
    if (!dest || !obj)
    {
      dest = dirs[dir+"down"];
      if (dest)
        obj = find_room(dest);
    }
    if (!dest || !obj)
    {
      dest = dirs[dir+"up"];
      if (dest)
        obj = find_room(dest);
    }
    if (!dest || !obj)
    {
      if (me->query("autodrive"))
      {
        if (random(2) == 0)
          dir = left_dirs[dir];
        else
          dir = right_dirs[dir];
        continue;
      }
      else
      {
        if (random(3) == 0)
          tell_object (who,"ǰ��("+chinese_dirs[dir]+
                           ")û��ʲô·�����ˡ�\n");
        return 0;
      }  
    }

    if (! obj->query("outdoors"))
    {
      if (me->query("autodrive"))
      {
        if (random(2) == 0)
          dir = left_dirs[dir];
        else
          dir = right_dirs[dir];
        continue;
      }
      else
      {
        if (random(3) == 0)
          tell_object (who,"ǰ��("+chinese_dirs[dir]+
                           ")�����������е�·��\n");
        return 0;
      }  
    }
    
    if (me->query("car_from/"+where->query("short"))==obj->query("short") &&
        me->query("autodrive") &&
        random(20))
      obj = 0;
  }
  if (me->query("autodrive"))
  {
    if (random(3) == 0)
      tell_object (who,"����������"+chinese_dirs[dir]+"��ʻ��\n");
    me->set("dir",dir);
  }
  return obj;
}

void check_move ()
{
  object me = this_object();
  object where = environment(me);
  object exit = 0;

  if (me->query("speed") == 0)
    return;

  exit = find_exit();
  me->add("distance",me->query("speed")/5+1);
  if (me->query("distance") < 100)
    return;

  me->set("distance",0);
  if (! exit)
  {
    remove_call_out("collision");
    call_out ("collision",1);
  }
  else
  {
    me->set("car_from/"+exit->query("short"),where->query("short"));
    message_vision (me->query("name")+"����"+where->query("short")+"��\n",me);
    me->move(exit);
    message_vision (me->query("name")+"����"+exit->query("short")+"��\n",me);
  }
}

void automate ()
{
  check_speed ();
  check_fuel ();
  check_miles (); 
  display_me ();
  remove_call_out("check_move");
  call_out("check_move",2); 
  remove_call_out("automate");
  call_out("automate",5);
}
