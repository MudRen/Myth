// room.c

//#pragma save_binary

#include <dbase.h>
#include <room.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

#include <banned.h>
static mapping doors;


int query_max_encumbrance() { return 100000000000; }
void random_position(int pos,object ob);
int query_max_items() {return 30;}
int query_max_datapos()
{ 
        
        if(query("position_max") 
           && (query("position_max") > 2 && query("position_max") <8 )) 
           return query("position_max");
         return 3;
}

 
object make_inventory(string file)
{
        object ob;

        file = resolve_path(0, file);
        ob = unew(file);
        if (ob) {
                ob->move(this_object());
                ob->set("startroom", base_name(this_object()));
        } else ob = filter_array( children(file), (: clonep :) )[<1];
        return ob;
}

void reset()
{
        mapping ob_list, ob;
        string *list;
        int i,j,pos;
        object *obs;
        
        //
        // Check loaded objects to match the objects specified in "objects"
        // while query("objects") is
        // ([ <object filename>: <amount>, ..... ])
        // and query_temp("objects") is
        // ([ <object filename>: ({ob1, ob2, ...}), .... ])
        //
        pos=this_object()->query_max_datapos();
        obs = all_inventory();
        i = sizeof(obs);
        while (i--)
                if (obs[i] && !obs[i]->value() && !obs[i]->query("location") && !obs[i]->is_character()
                && obs[i]->query("startroom") != base_name(this_object())
                && !obs[i]->query("sell_box")){
                        message_vision("$N��һ�������ˡ�\n", obs[i]);
                        destruct(obs[i]);
                }
        ob_list = query("objects");
        if( !mapp(ob_list) ) return;

        if( !mapp(ob = query_temp("objects")) )
                ob = allocate_mapping(sizeof(ob_list));
        list = keys(ob_list);
        for(i=0; i<sizeof(list); i++) {
                // Allocate an array if we have multiple same object specified.
                if(     undefinedp(ob[list[i]])
                &&      intp(ob_list[list[i]])
                &&      ob_list[list[i]] > 1 )
                        ob[list[i]] = allocate(ob_list[list[i]]);

                switch(ob_list[list[i]]) {
                case 1:
                        if( !ob[list[i]] ) ob[list[i]] = make_inventory(list[i]);
                        if( environment(ob[list[i]]) != this_object()
                            && !ob[list[i]]->query("location")
                            && !ob[list[i]]->return_home(this_object())) {
                                        ob[list[i]] = make_inventory(list[i]);
                        }
                        random_position(pos,ob[list[i]]);
                        break;
                default:
                        for(j=0; j<ob_list[list[i]]; j++) {
                                // If the object is gone, make another one.
                                if( !objectp(ob[list[i]][j]) ) {
                                        ob[list[i]][j] = make_inventory(list[i]);
                                        random_position(pos,ob[list[i]][j]);
                                        continue;
                                }
                                // Try to call the wandering npc come back here.
                                if( environment(ob[list[i]][j]) != this_object()
                                    && !ob[list[i]][j]->query("location")
                                    && !ob[list[i]][j]->return_home(this_object())) {
                                                ob[list[i]][j] = make_inventory(list[i]);
                                          random_position(pos,ob[list[i]][j]);
                                }
                        }
                }
        }
        set_temp("objects", ob);
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir)
{
        if( !mapp(doors) || undefinedp(doors[dir]) )
                return "��Ҫ��ʲô��\n";
        if( doors[dir]["status"] & DOOR_CLOSED )
                return "���" + doors[dir]["name"] + "�ǹ��ŵġ�\n";
        else
                return "���" + doors[dir]["name"] + "�ǿ��ŵġ�\n";
}

varargs int open_door(string dir, int from_other_side)
{
        mapping exits;
        object ob;

        if( !mapp(doors) || undefinedp(doors[dir]) )
                return notify_fail("�������û���š�\n");

        if( !(doors[dir]["status"] & DOOR_CLOSED) )
                return notify_fail( doors[dir]["name"] + "�Ѿ��ǿ��ŵ��ˡ�\n");

        exits = query("exits");
        if( !mapp(exits) || undefinedp(exits[dir]) )
                error("Room: open_door: attempt to open a door with out an exit.\n");

        if( from_other_side )
                message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "���ˡ�\n", this_object());
        else if( objectp(ob = find_object(exits[dir])) ) {
                if( !ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
        }

        doors[dir]["status"] &= (!DOOR_CLOSED);
        return 1;
}

varargs int close_door(string dir, int from_other_side)
{
        mapping exits;
        object ob;

        if( !mapp(doors) || undefinedp(doors[dir]) )
                return notify_fail("�������û���š�\n");

        if( (doors[dir]["status"] & DOOR_CLOSED) )
                return notify_fail( doors[dir]["name"] + "�Ѿ��ǹ��ŵ��ˡ�\n");

        exits = query("exits");
        if( !mapp(exits) || undefinedp(exits[dir]) )
                error("Room: close_door: attempt to open a door with out an exit.\n");

        if( from_other_side )
                message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "�����ˡ�\n", this_object());
        else if( objectp(ob = find_object(exits[dir])) ) {
                if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
        }

        doors[dir]["status"] |= DOOR_CLOSED;
        return 1;
}

int check_door(string dir, mapping door)
{
        // If we have no responding door, assume it is correct.
        if( !mapp(doors) || undefinedp(doors[dir]) ) return 1;

        door["status"] = doors[dir]["status"];
        return 1;
}

varargs void create_door(string dir, mixed data, string other_side_dir, int status)
{
        mapping d, exits, item_desc;
        object ob;

        exits = query("exits");
        if( !mapp(exits) || undefinedp(exits[dir]) )
                error("Room: create_door: attempt to create a door without exit.\n");

        // Compact mode.
        if( stringp(data) ) {
                d = allocate_mapping(4);
                d["name"] = data;
                d["id"] = ({ dir, data, "door" });
                d["other_side_dir"] = other_side_dir;
                d["status"] = status;
        } else if( mapp(data) )
                d = data;
        else
                error("Create_door: Invalid door data, string or mapping expected.\n");

        set("item_desc/" + dir, (: look_door, dir :) );

        if( objectp(ob = find_object(exits[dir])) ) {
                if( !ob->check_door(other_side_dir, d) )
                        return;
        }

        if( !mapp(doors) ) doors = ([ dir: d ]);
        else doors[dir] = d;
}

mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
        if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
        else return doors[dir][prop];
}

int valid_leave(object me, string dir)
{
        if( mapp(doors) && !undefinedp(doors[dir]) ) {
                if( doors[dir]["status"] & DOOR_CLOSED ) {
                    if(!userp(me)) {// allow npc to open doors.
                                    // mon 1/21/99
                        me->command("open "+
                                doors[dir]["name"]);
                        if(!(doors[dir]["status"] & DOOR_CLOSED))
                            return 1;
                    }

                    return notify_fail(
                            "������Ȱ�" + doors[dir]["name"] + "�򿪣�\n");
                }
                // if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
        }
        return 1;
}

void random_position(int pos,object ob)
{
        int n=20;
          ob->set_temp("position/yy",(random((pos * 2)-1) + n - (pos-1)));
          ob->set_temp("position/xx",(random((pos * 2)-1) + n - (pos-1)));
          ob->set_temp("position/zz",random(3));
}
//
///****hellfireroom ����//


void setup()
{
        int level= random(10)+5;
        int num= random(5)+1;
        
         if (query("no_fight"))
        {
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_magic", 1);
        }
      
        set("alternative_die",1);
        set("hellfireroom",1);
        
        if (!query("level")) set("level",level); //����ȼ��漰�ֵȼ�
        if (!query("npc_num")) set("npc_num",num);//�ֵĳ�����Ŀ��
       
        
        seteuid(getuid());
        this_object()->reset(); 

}

void setup2(){}


void init()
{

       add_action("do_quit",banned_action);
       add_action("do_cast","cast");
       add_action("do_exert","exert");
       add_action("block_cmd","",1);
    
     if(this_object()->query("zuandoors")) add_action("do_zuan","zuan");
     this_object()->init2();
}

int do_zuan()
{
        object me=this_player();
        if (me->is_busy() && me->query("no_move"))
        return notify_fail("����ʱ�����ƶ���\n");
        me->move(this_object()->query("zuandoors"));
        return 1;
}
int block_cmd()
{
        string verb = query_verb();
        object me = this_player();

        // wizard set hellfire allow all.
        if (wizardp(me) && me->query("env/hellfire"))
                 return 0;
        // ���߿�allow all
        if (!me->query_temp("hell_died"))
                 return 0;

        if (verb=="tell") return 0;
        if (verb=="chat") return 0; //allow chat
        if (verb=="help") return 0;
        if (verb=="look") return 0;
        if (verb=="quit") {
                this_player()->delete_temp("hell_died");
                this_player()->delete("env/invisibility");
                this_player()->move("/d/city/kezhan");
                }
        return 1;
}


int do_quit(string arg) {
  write("�㲻�����������������goָ�� ����gogo,��λ�ı����� gogogoָ�\n");
  if (wizardp(this_player())) write("��ʦ�����ͬһ·���ڵ�banned.h�ĵ���\n");
  return 1;
}
int do_cast(string arg) {

    if(this_object()->query("cast_closed")) return 0;
    if(!arg) return 0;
    if(arg !="transfer" ) return 0;
    command("cast transfer");
}
int do_exert(string arg) {
    
    if(this_object()->query("exert_closed")) return 0;
    if(!arg) return 0;
    if(arg !="recover" && arg != "heal" ) return 0;
    command("exert "+arg);
}


void alternative_die(object who)
{
     object killer,corpse;
     killer = who->query_temp("last_damage_from");

  if (userp(who)) 
  {
            message_vision("$N���ˡ�\n",who);
            who->set("kee",10);        
            who->set("sen",10);
            if(who->query("eff_kee")<10) who->set("eff_kee",10);
            if(who->query("eff_sen")<10) who->set("eff_sen",10);
            who->set("env/invisibility",1);
            who->set_temp("hell_died",1);
            if(!killer) killer=who;
            
            if( this_object()->query("corpse_make"))
               {
            if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )
                        corpse->move(this_object());
                                                        }

               all_inventory(this_object())->remove_killer(who);
             who->dismiss_team();
             who->remove_ride();
             who->delete_temp("last_fainted_from");

        }
        else {

        if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )
            corpse->move(this_object());
            message_vision("$N���ˡ�\n",who);
            who->reward();
            destruct(who);
            }


}
