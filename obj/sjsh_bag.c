//wirted by stey
#include <ansi.h>   
#define BAOSHI "/d/quest/baoshi/baoshi" 
inherit F_SAVE;   
inherit F_AUTOLOAD;  
inherit ITEM;   
void create()   
{        
    seteuid(0);
    set_name(HIC"百宝袋"NOR,({ "baibao bag", "bag", "object" }) );   
    set_weight(500);   
    if( clonep() )   
        set_default_object(__FILE__);   
    else {   
        set("value", 2000000);   
        set("unit","个");   
        set("color",HIB);  //HIB   
        set("no_put",1);   
        set("no_sell",1);   
        set("no_get",1);   
        set("no_give",1);   
        set("no_drop",1);   
        set("long",HIB"三界神话的百宝袋。\n"NOR);   
    }   
    setup();     
}   
    
void init ()   
{   
    if(query("owner_id")==getuid(this_player()))
    {
        add_action ("do_fang","fang");   
        add_action ("do_qu","na"); 
        add_action ("do_qu","qu");   
    }
}
void reset()
{
        if( !environment() ||  //mon 2/4/98
                query("owner_id") != getuid(environment()) )  
        {
                destruct(this_object());
                return;
        }
}  
  
void setup()
{
        ::setup();
}   
string query_save_file()  
{  
   string id;  
  
   id = query("owner_id");  
   if( !id ) return 0;  
  
   return sprintf(DATA_DIR "sjbaohe/%c/%s", id[0], id);  
}  
  
int save()  
{  
   return ::save();  
}  
void remove()
{
    save();
}

int do_fang(string arg)  
{  
    object obj,newobj;  
    object me= this_player();  
    object ob= this_object();  
    string thing,str;  
    int place,j;  

    int dx,p_limit;

    if(!arg)  
            return notify_fail("你要放什么？<指令>:fang xxx at xxx place\n");  

   if(ob->query("owner_id")!=me->query("id"))
   {
        ob->reset();
        write("百宝袋呼的一声消失在空气中？\n");  
        return 0;
    }

    if(me->is_busy()) 
        return notify_fail("你正忙着呢！n");  

    if (sscanf(arg,"%s at %d place",thing,place)!=2)     
        return notify_fail("你要放什么物品在什么位置？<指令>:fang xxx at xxx place\n");  
    
    if (!( obj=present (thing,me)))   
            return notify_fail("你身上没有这个物品。\n");   


    if( obj->query_unique() 
        || obj->query("weapon")  
        || obj->query("unique")  
        || obj->query("onwerid")
        || obj->query("no_bag")   
        || obj->query("no_put"))   
              return notify_fail("这件物品不能放进百宝带。\n");   

        if (ob->query("place_"+place)=="have")  
                return notify_fail("百宝袋第"+place+"个空位已经有物品了。\n");  
        
    dx=me->query("daoxing");
    p_limit =3+( dx-700000)/200000;
    if (p_limit > 18) p_limit = 18;

    if (place>p_limit)
    {   
           write("以你现在的修为只能放"+p_limit+"个物品进去。\n");
            return 1;
    }
          
    if ( obj->query("b_lvl") || obj->query("reward_lvl"))  
    {  
        ob->set("place_"+place,"have");  
        ob->set("place_"+place+"obj/obj_name",obj->query("name"));  
        ob->set("place_"+place+"obj/obj_id",obj->query("id"));  
        ob->set("place_"+place+"obj/obj_lvl",obj->query("b_lvl"));  
    }  
    else  
    if(obj->query("material"))  
    {  
        if(!obj->query("weapon_prop/damage"))  
        {  
            ob->set("place_"+place,"have");  
            ob->set("place_"+place+"obj/obj_name",obj->query("name"));  
            ob->set("place_"+place+"obj/obj_id",obj->query("id"));  
            ob->set("place_"+place+"obj/obj_long",obj->query("long"));  
            ob->set("place_"+place+"obj/obj_file",base_name(obj));  
            ob->set("place_"+place+"obj/obj_weight",obj->query_weight());                                             
            ob->set("place_"+place+"obj/objobj_armor_prop_armor",obj->query("armor_prop/armor"));  
            ob->set("place_"+place+"obj/objobj_armor_prop_dodge",obj->query("armor_prop/dodge"));  
            ob->set("place_"+place+"obj/objobj_armor_prop_spell",obj->query("armor_prop/spell"));  

             if(obj->query("inset_num"))  
                ob->set("place_"+place+"obj/obj_inset_num",obj->query("inset_num"));  
             if(obj->query("old_long"))   
                ob->set("place_"+place+"obj/obj_old_long",obj->query("old_long"));  
             if(obj->query("old_ee"))   
                ob->set("place_"+place+"obj/obj_old_ee",obj->query("old_ee"));  
        }
        else  
        {  
            ob->set("place_"+place,"have");  
            ob->set("place_"+place+"obj/obj_name",obj->query("name"));  
            ob->set("place_"+place+"obj/obj_id",obj->query("id"));  
            ob->set("place_"+place+"obj/obj_long",obj->query("long"));  
            ob->set("place_"+place+"obj/obj_file",base_name(obj));  
            ob->set("place_"+place+"obj/obj_material",obj->query("material"));  
            ob->set("place_"+place+"obj/obj_weight",obj->query_weight());  
            ob->set("place_"+place+"obj/obj_weapon_prop_damage",obj->query("weapon_prop/damage"));  
            ob->set("place_"+place+"obj/obj_weapon_prop_intelligence",obj->query("weapon_prop/intelligence"));  
              
             if(obj->query("inset_num"))  
                ob->set("place_"+place+"obj/obj_inset_num",obj->query("inset_num"));  
             if(obj->query("old_long"))   
                ob->set("place_"+place+"obj/obj_old_long",obj->query("old_long"));  
             if(obj->query("old_ee"))   
                ob->set("place_"+place+"obj/obj_old_ee",obj->query("old_ee"));  
        }  
    }  
    else
    {  
        return notify_fail("这件物品不能放进百宝带。\n"); 
    }  
            
  if(obj->query("no_sell")) 
      ob->set("place_"+place+"obj/obj_no_sell",1);  
  if(obj->query("no_drop")) 
      ob->set("place_"+place+"obj/obj_no_drop",1);  
  if(obj->query("no_put")) 
      ob->set("place_"+place+"obj/obj_no_put",1);  
  if(obj->query("no_give")) 
      ob->set("place_"+place+"obj/obj_no_give",1);  
  if(obj->query("no_get")) 
      ob->set("place_"+place+"obj/obj_no_get",1);  
                
  str=HIB"三界神话的百宝袋。\n"NOR;  
  str+=HIG"————————————————————————————\n"NOR;  
  for (j = 1; j<19; j++)
  {  
    if(j==place)  
     {  
         ob->set("place_"+j,"have");  
         str+="第"+j+"物品空间："+obj->name()+"   ("+obj->query("id")+")\n";        
         continue;
    }  
                 
    if(!ob->query("place_"+j))  
    {
        ob->set("place_"+j,"none");     
        str+="第"+j+"物品空间：none\n";  
        continue;
    }  

    if(ob->query("place_"+j)=="none")  
    {
        ob->set("place_"+j,"none");     
        str+="第"+j+"物品空间：none\n";  
        continue;
    }  
    if(ob->query("place_"+j)=="have")  
    {
        str+="第"+j+"物品空间："+ob->query("place_"+j+"obj/obj_name")  
           +"   ("+ob->query("place_"+j+"obj/obj_id")+")\n";}  
    }  
    
     str+=HIG"————————————————————————————\n"NOR;  
    
     if(obj->query("no_sell")) 
          ob->set("place_"+place+"obj/obj_no_sell",1);  
          
      ob->set("long",str);  
      ob->save();  
      message_vision("$N把一"+obj->query("unit")+obj->name()+NOR+"放进三界神话的百宝袋。\n",me);  
      destruct(obj);  
      me->start_busy(2); 
      return 1;  
}     
 
int do_qu(string arg)  
{ 
        object newobj;  
        object me= this_player();  
        object ob= this_object(); 
        string str;   
        int place,j;  
        if(!arg)  
                return notify_fail("你要放什么？<指令>:na xxx from bag\n");  
       if(ob->query("owner_id")!=me->query("id"))
                            return notify_fail("你要干什么？\n");  
        if(me->is_busy()) 
                return notify_fail("你正忙着呢！n");    
        if (sscanf(arg,"%d from bag",place)!=1)     
                return notify_fail("你要放什么物品在什么位置？<指令>:na xxx from bag\n"); 
        if (place <1 || place >18)  
                return notify_fail("百宝袋只有18个空间。\n");  
        if (ob->query("place_"+place)!="have")  
                return notify_fail("百宝袋第"+place+"个空间是空的。\n");  
         
         
        if(ob->query("place_"+place+"obj/obj_lvl")) 
        { 
                newobj=new(BAOSHI); 
                BAOSHI->changename(newobj,(int)ob->query("place_"+place+"obj/obj_lvl"));  
        } 
        else 
        if( ob->query("place_"+place+"obj/obj_weapon_prop_damage")) 
        { 
                newobj=new(ob->query("place_"+place+"obj/obj_file"));  
                if(!newobj)     return notify_fail("取物品失败。\n");  
                newobj->set("name", ob->query("place_"+place+"obj/obj_name")); 
                newobj->set("long", ob->query("place_"+place+"obj/obj_long")); 
                newobj->set_weight(ob->query("place_"+place+"obj/obj_weight")); 
                newobj->set("material", ob->query("place_"+place+"obj/obj_material")); 
                newobj->set("weapon_prop_damage", ob->query("place_"+place+"obj/obj_weapon_prop_damage")); 
                newobj->set("prop_intelligence", ob->query("place_"+place+"obj/obj_prop_intelligence")); 
                 
                 
                 
                 if(ob->query("place_"+place+"obj/obj_inset_num")) 
                 newobj->set("inset_num",(int)ob->query("place_"+place+"obj/obj_inset_num")); 
                 if(ob->query("place_"+place+"obj/obj_old_long")) 
                 newobj->set("old_long",ob->query("place_"+place+"obj/obj_old_long")); 
                  if(ob->query("place_"+place+"obj/obj_old_ee")) 
                 newobj->set("old_ee",ob->query("place_"+place+"obj/obj_iold_ee"));  
                    
        }else 
        if (ob->query("place_"+place+"obj/obj_armor_prop_armor")) 
        { 
                newobj=new(ob->query("place_"+place+"obj/obj_file"));  
                if(!newobj)     return notify_fail("取物品失败。\n");  
                newobj->set("name", ob->query("place_"+place+"obj/obj_name")); 
                newobj->set("long", ob->query("place_"+place+"obj/obj_long")); 
                newobj->set_weight(ob->query("place_"+place+"obj/obj_weight")); 
                 
                newobj->set("armor_prop_armor", ob->query("place_"+place+"obj/obj_armor_prop_armor")); 
                newobj->set("armor_prop_dodge", ob->query("place_"+place+"obj/obj_armor_prop_dodge")); 
                newobj->set("armor_prop_spell", ob->query("place_"+place+"obj/obj_armor_prop_spell")); 
                 
                 
                 if(ob->query("place_"+place+"obj/obj_inset_num")) 
                 newobj->set("inset_num",(int)ob->query("place_"+place+"obj/obj_inset_num")); 
                 if(ob->query("place_"+place+"obj/obj_old_long")) 
                 newobj->set("old_long",ob->query("place_"+place+"obj/obj_old_long")); 
                  if(ob->query("place_"+place+"obj/obj_old_ee")) 
                 newobj->set("old_ee",ob->query("place_"+place+"obj/obj_iold_ee"));  
       }else 
       { 
        newobj=new(ob->query("place_"+place+"obj/obj_file"));  
                if(!newobj)     return notify_fail("取物品失败。\n"); } 
                 
        
       if(ob->query("place_"+place+"obj/obj_no_sell")) 
                   newobj->set("no_sell",1);  
       if(ob->query("place_"+place+"obj/obj_no_drop")) 
                   newobj->set("no_drop",1);                     
       if(ob->query("place_"+place+"obj/obj_no_get")) 
                   newobj->set("no_get",1); 
       if(ob->query("place_"+place+"obj/obj_no_put")) 
                   newobj->set("no_put",1);  
       if(ob->query("place_"+place+"obj/obj_no_give")) 
                   newobj->set("no_give",1); 
       if(newobj->move(me)) 
       {             
                str=HIB"三界神话的百宝袋。\n"NOR;  
          str+=HIG"————————————————————————————\n"NOR;  
          for (j = 1; j<19; j++) {  
               if(j==place)  
                         {  
                         ob->set("place_"+j,"none");  
                          str+="第"+j+"物品空间：none\n";  
                          continue;}  
                 
               if(!ob->query("place_"+j))  
                         { ob->set("place_"+j,"none");     
                                str+="第"+j+"物品空间：none\n";  
                                continue;}  
               if(ob->query("place_"+j)=="none")  
                          { ob->set("place_"+j,"none");     
                                str+="第"+j+"物品空间：none\n";  
                                continue;}  
               if(ob->query("place_"+j)=="have")  
                          {     str+="第"+j+"物品空间："+ob->query("place_"+j+"obj/obj_name")  
                                       +"   ("+ob->query("place_"+j+"obj/obj_id")+")\n";}  
                                    
                                    
                                }  
          str+=HIG"————————————————————————————\n"NOR; 
          ob->set("long",str);  
          message_vision("$N从三界神话的百宝袋拿出一"+newobj->query("unit")+newobj->name()+NOR+"。\n",me);  
          ob->delete("place_"+place+"obj"); 
          ob->save(); 
       me->start_busy(3); 
        return 1; 
        } 
        else{ 
        return notify_fail("取物品失败。\n");} 
} 

