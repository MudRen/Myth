// unique.c

#include <ansi.h>
#include <dbase.h>

inherit F_ONEOWNER;

nosave int compare_number = -1;
// mon 4/5/98

int query_unique() { return 1; }
int query_compare_number() { return compare_number; }

// This function returns the number of objects in the mud
varargs int query_number() { 
   int  num;

   num = sizeof(filter_array(children(file_name(this_object())), (:clonep:)));
   return num;
}

// This function sets the compare_number (used by /std/char/npc )
void set_compare_number()
{
   compare_number = 1;
}

void reset_compare_number()
{
   compare_number = -1;
}

// This function returns 1 if the object is already in mud
varargs int in_mud()
{
   if(compare_number<0) compare_number=1;
   // mon 4/5/98, set default number.

   if( query_number() >= compare_number )
   // mon 4/5/98 changed > to >= and modified 
   //  /std/char/npc.c accordingly.
          return 1;
   return 0;
}

// This function returns the original file if in_mud() return 0
// or return replace_file.
varargs string clone_file()
{
   string rev;
   object me = this_object();

   if( !in_mud() )
          return file_name(me);
   else   {
          if( stringp(rev=me->query("replace_file")) )
                 return rev; 
      return ""; 
   }
}

//only the first user owner can own this unique items.
// can't give it to others.
void init()
{
  check_owner();
}


// This function returns 1 if this_object() is not the unique clone in
// the mud. Note that calling this function on master copy always return
// 0.
nomask int violate_unique()
{
        object *ob;

        if( !clonep(this_object()) ) return 0;

        // Find all the cloned instance of this_object()
        ob = filter_array( children(base_name(this_object())), (: clonep :) );

        return sizeof(ob) > 1;
}

// This function returns the replica of this_object() if any.
object create_replica()
{
        string replica;
        object obj;

        seteuid(getuid());
        if( stringp(replica = this_object()->query("replica_ob")) )
                obj = new(replica);
        else
                obj = 0;
        destruct(this_object());
        return obj;
}
